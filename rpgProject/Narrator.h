#pragma once

#include "Menu.h"
#include "Actor.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
#include "Encounter.h"

class Narrator
{
public:
	void startGreeting();

	// character creation
	Actor* characterCreator();

	// encounters
	void encounter(Actor& player, Actor& enemy);

	// dummy inventory purchase
	void buySomething(Actor& player);

private:
	
	string version{ "v0.01d" };
};

