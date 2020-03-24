#pragma once
#include "GameState.h"
class WeaponShopMenu :
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

	static WeaponShopMenu* Instance()
	{
		return &m_WeaponShopMenu;
	}

protected:
	WeaponShopMenu() {}

private:
	int choice{};
	static WeaponShopMenu m_WeaponShopMenu;
	std::vector<string> options{ "Display Player", "Display Class Information",
		"Display Money", "Display Upgrades", "Display Potions", "Buy Something",
		"Use A Potion", "Display Enemies", "Attack", "Random Encounter", "Quit" };
	const string name{ "Weapon Menu" };
};

