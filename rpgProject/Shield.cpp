#include "Shield.h"

Shield::Shield()
{
	name = "Shield";
	armorValue = 2;
	durability = 20;
	value = 450;
}

Shield::Shield(string name, int armorValue, int durability, int value)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
}

Shield::~Shield()
{
}

string Shield::GetName() const
{
	return this->name;
}

int Shield::GetArmorValue() const
{
	return this->armorValue;
}

int Shield::GetDurability() const
{
	return this->durability;
}

int Shield::GetValue() const
{
	return this->value;
}
