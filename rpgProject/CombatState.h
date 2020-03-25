#pragma once
#include "GameState.h"
class CombatState :
	public GameState
{
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
	bool firstRound{ true };
	int choice{};
	static CombatState m_CombatState;
	std::vector<std::string> options{ "Attack", "Use Potion" };
	const std::string name{ "Combat" };

	std::vector<Actor*> initiativeOrder;
};

