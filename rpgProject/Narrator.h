#pragma once

#include "Actor.h"

#include <string>

class Narrator
{
public:
	void startGreeting();

	// menu builder
	void menuBuilder(int decisions, std::string listOfDecisions[]);

	// character creation
	void characterCreator();

	// encounters
	void encounter(Actor* player, Actor* enemy);

private:
	std::string version{ "v0.01b" };
};

