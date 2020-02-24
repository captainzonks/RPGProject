#pragma once

#include "Menu.h"
#include "Actor.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Dwarf
	: public Actor
{
public:

	// constructors
	Dwarf();
	Dwarf(string name);

	// destructor
	virtual ~Dwarf() override;

	// character creation functions
	virtual void rollStats() override;

	// getter
	virtual void display();

private:

	string race{ "Dwarf" };
	int walkingSpeed{ 25 };

};
