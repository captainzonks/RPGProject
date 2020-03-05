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

	void StartGreeting();

	// character creation
	std::shared_ptr<Actor> CharacterCreator();

	// inventory creation
	void BuySomething(std::shared_ptr<Actor> player);
	bool CheckPrice(std::shared_ptr<Actor> player, int price);

private:
	
	string version{ "v0.01g" };
};

