#pragma once

#include "Menu.h"
#include "Actor.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
class Elf :
	public Actor
{
public:

	// constructors
	Elf();
	Elf(int identifier);
	Elf(string name);

	// destructor
	virtual ~Elf() override;

	// character creation functions
	virtual void RollStats() override;

	// getter
	virtual string GetRace() override;

private:

	string race{ "Elf" };
	int walkingSpeed{ 30 };

};

