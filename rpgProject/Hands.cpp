#include "Hands.h"

Hands::Hands()
{
	this->name = "Hands";
	this->armorValue = 2;
	this->level = 1;
	this->durability = 20;
	this->value = 300;
}

Hands::Hands(string name, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;
}

Hands::~Hands()
{
}