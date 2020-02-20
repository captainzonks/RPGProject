#pragma once

#include "Weapons.h"

#include <string>

using std::string;

class Sword :
	public Weapons
{
public:
	string getName();
	int getAttackDie();
	int getDurability();

private:
	string name{ "Sword" };
	int attackDie{ 6 };
	int durability{ 20 };
};

