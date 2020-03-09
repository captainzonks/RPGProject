#include "Helmet.h"

Helmet::Helmet()
{
	this->name = "Helmet";
	this->armorValue = 1;
	this->level = 1;
	this->durability = 20;
	this->value = 300;
}

Helmet::Helmet(string name, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;
}

Helmet::~Helmet()
{
}