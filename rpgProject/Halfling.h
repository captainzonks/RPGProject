#pragma once

#include "Menu.h"
#include "Actor.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Halfling
	: public Actor
{
public:

	// constructors
	Halfling();
	Halfling(string name);

	// getter
	string getRace();
	void display();

	// race modifier
	void raceModification();

private:

	string race{ "Halfling" };
	int walkingSpeed{ 25 };

};

