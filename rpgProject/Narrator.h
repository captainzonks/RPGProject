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

	// inventory creation
	Sword* makeASword();

private:
	
	string version{ "v0.01d" };
};

