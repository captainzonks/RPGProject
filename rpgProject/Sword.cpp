#include "Sword.h"

Sword::Sword()
{
	name = "Sword";
	attackDie = 6;
	durability = 20;
	value = 250;
}

Sword::Sword(string name, int attackDie, int durability, int value)
{
	this->name = name;
	this->durability = durability;
	this->value = value;
	this->attackDie = attackDie;
}

Sword::~Sword()
{
}

string Sword::GetName() const
{
	return this->name;
}

int Sword::GetAttackDie() const
{
	return this->attackDie;
}

int Sword::GetDurability() const
{
	return this->durability;
}

int Sword::GetValue() const
{
	return this->value;
}
