#pragma once

#include "Actor.h"

#include <string>

class Narrator
{
public:
	void startGreeting();

	// character creation
	void characterCreator();

	// encounters
	void encounter(Actor* player);

private:
	std::string version{ "v0.01" };
};

