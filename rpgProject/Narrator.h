#pragma once

#include <memory>

#include "Menu.h"
//#include "Human.h"
//#include "Dwarf.h"
//#include "Elf.h"
//#include "Halfling.h"
#include "Item.h"
#include "Weapon.h"
#include "Sword.h"
#include "Armor.h"
#include "Shield.h"
#include "Helmet.h"
#include "Chest.h"
#include "Legs.h"
#include "Hands.h"
#include "Boots.h"
#include "Potion.h"
#include "Fighter.h"

class Narrator
{
public:
	void StartGreeting();

	// character creation
	Actor* CharacterCreator();

	// upgrades
	void BuySomething(Actor& player);
	bool CheckPrice(Actor& player, int price) const;
	void Upgrader(Actor& actor);

	// shop function
	void DisplayPrice(const int copper) const;

	// get player item level
	int GetPlayerAverageLevel(Actor& player) const;

private:
	
	string version{ "v0.01g" };
};

