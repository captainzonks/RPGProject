#pragma once
#include "GameState.h"
class ShopMenuState :
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

	static ShopMenuState* Instance()
	{
		return &m_ShopMenuState;
	}
protected:
	ShopMenuState() {}

	int choice{};
	static ShopMenuState m_ShopMenuState;
	std::vector<string> options{ "Buy Armor", "Buy Weapons", "Quit" };
	const string name{ "Shop Menu" };
};

