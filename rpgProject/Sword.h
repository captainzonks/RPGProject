#pragma once

#include "Item.h"

#include <string>

using std::string;

class Sword :
	public Item
{
public:

	Sword(string name);

	string getName();
	int getAttackDie();
	int getDurability();

private:
	string name{ "Sword" };
	int attackDie{ 6 };
	int durability{ 20 };
};

