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
	Halfling(int identifier);
	Halfling(string name);

	// destructor
	virtual ~Halfling() override;

	// character creation functions
	virtual void rollStats() override;

	// getter
	virtual void display() override;
	virtual string getRace() override;

private:

	string race{ "Elf" };
	int walkingSpeed{ 25 };

};

