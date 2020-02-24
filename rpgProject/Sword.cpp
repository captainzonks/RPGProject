#include "Sword.h"

Sword::Sword()
{
	name = "Sword";
	attackDie = 6;
	durability = 20;
}

Sword::Sword(string name, int attackDie)
{
	this->name = name;
	durability = 20;
	this->attackDie = attackDie;
}

Sword::~Sword()
{
}

string Sword::getName() const
{
	return this->name;
}

int Sword::getAttackDie() const
{
	return this->attackDie;
}

int Sword::getDurability() const
{
	return this->durability;
}