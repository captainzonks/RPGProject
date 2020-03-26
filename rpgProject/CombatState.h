#pragma once

#include "GameState.h"

class CombatState :
	public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static CombatState* Instance()
	{
		return &m_CombatState;
	}

	void HandleCombat(Game* game);

	void SortInitiativeOrder();
	void DisplayIniatives();
	Actor* PickTarget(Game* game);

protected:
	CombatState() {}

	static CombatState m_CombatState;
	EnemyManager* manager{ nullptr };
	Actor* target{ nullptr };

	bool firstRound{ true };
	std::vector<Actor*> initiativeOrder;

	int choice{};
	std::vector<std::string> options{ "Attack", "Use Potion" };
	const std::string name{ "Combat" };
};

