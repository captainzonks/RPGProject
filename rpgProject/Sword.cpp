#include "Sword.h"

Sword::Sword()
{
	name = "Sword";
	attackDie = 6;
	durability = 20;
	value = 250;
	level = 1;
	damageType = DAMAGE_TYPE::SLASHING;
}

Sword::Sword(string name, int attackDie, DAMAGE_TYPE damageType, int durability, int value, int level)
{
	this->name = name;
	this->durability = durability;
	this->value = value;
	this->attackDie = attackDie;
	this->level = level;
	this->damageType = damageType;
}

Sword::~Sword()
{
}