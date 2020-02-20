#include "Sword.h"

Sword::Sword(string name)
	: Item(name)
{
	this->name = name;
}

string Sword::getName()
{
	return this->name;
}

int Sword::getAttackDie()
{
	return this->attackDie;
}

int Sword::getDurability()
{
	return durability;
}
