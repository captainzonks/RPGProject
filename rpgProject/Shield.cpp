#include "Shield.h"

Shield::Shield()
{
	this->name = "Shield";
	this->armorValue = 2;
	this->durability = 20;
	this->value = 450;
	this->level = 1;
	this->armorType = ARMOR_TYPE::SHIELD;
}

Shield::Shield(string name, int armorValue, int durability, int value, int level)
{
	this->name = name;
	this->armorValue = armorValue;
	this->durability = durability;
	this->value = value;
	this->level = level;
	this->armorType = ARMOR_TYPE::SHIELD;
}

Shield::~Shield()
{
}