#include "Chest.h"

Chest::Chest()
{
	// default constructor makes light armor
	this->name = "Chest";
	this->armorType = ARMOR_TYPE::LIGHT_ARMOR;
	this->armorValue = 2;
	this->level = 1;
	this->durability = 20;
	this->value = 750;
}

Chest::Chest(std::string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level)
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

Chest::~Chest()
{
}