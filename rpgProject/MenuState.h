#pragma once

#include "GameState.h"
#include "ShopMenuState.h"

class MainMenuState :
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
		"Use A Potion", "Display Enemies", "Attack", "Random Encounter", "Exit Game" };
	const std::string name{ "Main Menu" };
};

