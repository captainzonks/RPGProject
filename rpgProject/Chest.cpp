#include "Chest.h"

Chest::Chest()
{
	this->name = "Chest";
	this->armorValue = 2;
	this->level = 1;
	this->durability = 20;
	this->value = 750;
}

Chest::Chest(string name, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;
}

Chest::~Chest()
{
}