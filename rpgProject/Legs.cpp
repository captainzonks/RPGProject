#include "Legs.h"

Legs::Legs()
{
	this->name = "Legs";
	this->armorValue = 2;
	this->level = 1;
	this->durability = 20;
	this->value = 580;
}

Legs::Legs(string name, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;
}

Legs::~Legs()
{
}