#include "ShortBow.h"

ShortBow::ShortBow()
{
	this->name = "Shortbow";
	this->attackDie = 6;
	this->durability = 20;
	this->value = 2500;
	this->level = 1;
	this->damageType = DAMAGE_TYPE::PIERCING;
	this->weaponType = WEAPON_TYPE::RANGED;
	this->weaponProficiency = WEAPON_PROFICIENCY::SIMPLE;
}

ShortBow::ShortBow(string name, int attackDie, DAMAGE_TYPE damageType, int durability, int value, int level)
{
	this->name = name;
	this->durability = durability;
	this->value = value;
	this->attackDie = attackDie;
	this->level = level;
	this->damageType = damageType;
	this->weaponType = WEAPON_TYPE::RANGED;
	this->weaponProficiency = WEAPON_PROFICIENCY::SIMPLE;
}

ShortBow::~ShortBow()
{
}
