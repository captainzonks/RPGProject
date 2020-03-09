#include "Elf.h"

Elf::Elf()
{
	cout << "Elf constructor called" << endl; // debug
}

Elf::Elf(int identifier)
{
	cout << "Elf (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Elf";
	this->RollStats();
	this->identifier = identifier;
	this->race = "Elf";
	this->level = 1;
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Elf::Elf(string name)
{
	cout << "Elf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->RollStats();
	this->race = "Elf";
	this->level = 1;
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Elf::~Elf()
{
	std::cout << "Elf destructor called" << endl;
}

void Elf::RollStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6);
	this->dexterity = RollDiceIgnoreLowest(4, 6) + 2;
	this->constitution = RollDiceIgnoreLowest(4, 6);
	this->intelligence = RollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

string Elf::GetRace()
{
	return this->race;
}
