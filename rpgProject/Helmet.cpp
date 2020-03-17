#include "Helmet.h"

Helmet::Helmet()
{
	// default constructor makes light armor
	this->name = "Helmet";
	this->armorType = ARMOR_TYPE::LIGHT_ARMOR;
	this->armorValue = 1;
	this->level = 1;
	this->durability = 20;
	this->value = 300;
}

Helmet::Helmet(string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorType = armorType;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;

	if (armorType == ARMOR_TYPE::HEAVY_ARMOR)
		stealthDisadvantage = true;
}

Helmet::~Helmet()
{
}