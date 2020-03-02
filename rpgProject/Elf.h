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
	virtual void rollStats() override;

	// getter
	virtual void display();

private:

	string race{ "Elf" };
	int walkingSpeed{ 30 };

};

