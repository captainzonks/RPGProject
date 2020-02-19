#pragma once

#include "Menu.h"
#include "Actor.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Human
	: public Actor
{
public:

	// constructors
	Human();
	Human(string name);

	// display
	void display();

	// getter
	string getRace();

	// race modifier
	void raceModification();

private:

	string race{ "Human" };
	int walkingSpeed{ 30 };

};

