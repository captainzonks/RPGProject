#pragma once

#include <memory>

#include "Menu.h"
#include "Actor.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
// #include "Encounter.h"
#include "Item.h"
#include "Sword.h"
#include "Armor.h"
#include "Shield.h"

class Narrator
{
public:

	enum class ITEM_TYPES {
		SWORD = 1,
		SHIELD
	};

	void startGreeting();

	// character creation
	std::shared_ptr<Actor> characterCreator();

	// encounters
	// void encounter(Actor& player, Actor& enemy);

	// inventory creation
	void buySomething(std::shared_ptr<Actor> player);
	bool CheckPrice(std::shared_ptr<Actor> player, int price);
	std::unique_ptr<Item> makeAnItem(ITEM_TYPES itemType);

	//Sword* makeASword();

private:
	
	string version{ "v0.01f" };
};

