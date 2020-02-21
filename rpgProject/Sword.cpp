#include "Sword.h"

Sword::Sword()
{
}

Sword::Sword(string name)
	: Item(name)
{
	this->name = name;
}

Sword::~Sword()
{
}

string Sword::getName()
{
	return name;
}

int Sword::getAttackDie()
{
	return attackDie;
}

int Sword::getDurability()
{
	return durability;
}