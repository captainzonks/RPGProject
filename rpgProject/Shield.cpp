#include "Shield.h"

Shield::Shield()
{
	name = "Shield";
	armorValue = 2;
	durability = 20;
}

Shield::Shield(string name, int armorValue)
{
	this->name = name;
	this->armorValue = armorValue;
}

Shield::~Shield()
{
}

string Shield::getName() const
{
	return this->name;
}

int Shield::getArmorValue() const
{
	return this->armorValue;
}

int Shield::getDurability() const
{
	return this->durability;
}
