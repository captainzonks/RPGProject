#include "Helmet.h"

Helmet::Helmet()
{
	// default constructor makes light armor
	this->name = "Helmet";
	this->armorType = armor_type::light_armor;
	this->armorValue = 1;
	this->level = 1;
	this->durability = 20;
	this->value = 300;
}

Helmet::Helmet(std::string name, armor_type armorType, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorType = armorType;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;

	if (armorType == armor_type::heavy_armor)
		stealthDisadvantage = true;
}

Helmet::~Helmet()
{
}