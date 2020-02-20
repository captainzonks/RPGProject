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

	// getter
	string getRace();
	void display();

	// race modifier
	void raceModification();

private:

	string race{ "Dwarf" };
	int walkingSpeed{ 25 };

};

