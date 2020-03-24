#include "Sword.h"

Sword::Sword()
{
	this->name = "Sword";
	this->attackDie = 6;
	this->durability = 20;
	this->value = 1000;
	this->level = 1;
	this->damageType = DAMAGE_TYPE::SLASHING;
	this->weaponType = WEAPON_TYPE::MELEE;
	this->weaponProficiency = WEAPON_PROFICIENCY::MARTIAL;
}

Sword::Sword(std::string name, int attackDie, DAMAGE_TYPE damageType, int durability, int value, int level)
{
	this->name = name;
	this->durability = durability;
	this->value = value;
	this->attackDie = attackDie;
	this->level = level;
	this->damageType = damageType;
	this->weaponType = WEAPON_TYPE::MELEE;
	this->weaponProficiency = WEAPON_PROFICIENCY::MARTIAL;
}

Sword::~Sword()
{
}