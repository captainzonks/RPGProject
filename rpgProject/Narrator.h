#pragma once

#include <memory>

#include "Menu.h"
#include "Actor.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
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

class Narrator
{
public:
	void StartGreeting();

	// character creation
	std::shared_ptr<Actor> CharacterCreator();

	// upgrades
	void BuySomething(std::shared_ptr<Actor> player);
	bool CheckPrice(std::shared_ptr<Actor> player, int price);
	void Upgrader(std::shared_ptr<Actor> actor);

	// shop function
	void DisplayPrice(const int copper) const;

	// get player item level
	int GetPlayerAverageLevel(std::shared_ptr<Actor> player);

private:
	
	string version{ "v0.01g" };
};

