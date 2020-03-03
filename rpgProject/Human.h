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
	Human(int identifier);
	Human(string name);

	// destructor
	virtual ~Human() override;

	// character creation functions
	virtual void rollStats() override;

	// getter
	virtual void display() override;
	virtual string getRace() override;

private:

	string race{ "Human" };
	int walkingSpeed{ 30 };

};

