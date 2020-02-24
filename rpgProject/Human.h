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

	// destructor
	virtual ~Human() override;

	// character creation functions
	virtual void rollStats() override;

	// getter
	virtual void display();

private:

	string race{ "Human" };
	int walkingSpeed{ 30 };

};

