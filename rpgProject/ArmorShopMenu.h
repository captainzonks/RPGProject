#pragma once
#include "GameState.h"
class ArmorShopMenu :
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

	static ArmorShopMenu* Instance()
	{
		return &m_ArmorShopMenu;
	}

protected:
	ArmorShopMenu() {}

private:
	int choice{};
	static ArmorShopMenu m_ArmorShopMenu;
	std::vector<string> options{ "Display Player", "Display Class Information",
		"Display Money", "Display Upgrades", "Display Potions", "Buy Something",
		"Use A Potion", "Display Enemies", "Attack", "Random Encounter", "Quit" };
	const string name{ "Armor Menu" };
};

