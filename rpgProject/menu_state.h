#pragma once

#include "GameState.h"
#include "ShopMenuState.h"
#include "CombatState.h"

class MainMenuState :
	public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(game* game);
	void Update(game* game);
	void Draw(game* game);

	static MainMenuState* Instance()
	{
		return &m_MainMenuState;
	}

protected:
	MainMenuState() {}
	int choice{};
	static MainMenuState m_MainMenuState;
	std::vector<std::string> options{ "Display Player", "Display Class Information",
		"Display Money", "Display Upgrades", "Display Potions", "Buy Something",
		"Use A Potion", "Display Enemies", "Attack", "Add Enemy", "Exit game" };
	const std::string name{ "Main Menu" };
};

