#pragma once

#include "Menu.h"
#include "Actor.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Human
	: Actor
{
public:

	// constructors
	Human();

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

