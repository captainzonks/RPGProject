#include "Shield.h"

Shield::Shield()
{
}

Shield::Shield(string name, int armorValue)
	: Item(name)
{
	this->name = name;
	this->armorValue = armorValue;
}

Shield::~Shield()
{
}

string Shield::getName()
{
	return this->name;
}

int Shield::getArmorValue()
{
	return this->armorValue;
}