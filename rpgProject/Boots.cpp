#include "Boots.h"

Boots::Boots()
{
	this->name = "Boots";
	this->armorValue = 2;
	this->level = 1;
	this->durability = 20;
	this->value = 300;
}

Boots::Boots(string name, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;
}

Boots::~Boots()
{
}