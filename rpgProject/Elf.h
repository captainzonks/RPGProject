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
	Elf(string name);

	virtual ~Elf() override;

	// getter
	string getRace();
	void display();

	// race modifier
	void raceModification();

private:

	string race{ "Elf" };
	int walkingSpeed{ 30 };

};

