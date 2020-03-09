#include "Halfling.h"

Halfling::Halfling()
{
	cout << "Halfling constructor called" << endl; // debug
}

Halfling::Halfling(int identifier)
{
	cout << "Halfling (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Halfling";
	this->RollStats();
	this->identifier = identifier;
	this->race = "Halfling";
	this->level = 1;
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Halfling::Halfling(string name)
{
	cout << "Halfling (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->RollStats();
	this->race = "Halfling";
	this->level = 1;
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Halfling::~Halfling()
{
	std::cout << "Halfling destructor called" << endl;
}

void Halfling::RollStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6);
	this->dexterity = RollDiceIgnoreLowest(4, 6);
	this->constitution = RollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = RollDiceIgnoreLowest(4, 6);
	this->wisdom = RollDiceIgnoreLowest(4, 6);
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

string Halfling::GetRace()
{
	return this->race;
}
