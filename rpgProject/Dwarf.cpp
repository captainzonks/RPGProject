#include "Dwarf.h"

Dwarf::Dwarf()
{
	cout << "Dwarf constructor called" << endl; // debug
}

Dwarf::Dwarf(int identifier)
{
	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Dwarf"; // temporary debug value
	this->RollStats();
	this->identifier = identifier;
	this->race = "Dwarf";
	this->level = 1;
	this->health = 8 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 10);
	this->resistance = DAMAGE_TYPE::POISON;
}

Dwarf::Dwarf(string name)
{
	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->RollStats();
	this->race = "Dwarf";
	this->level = 1;
	this->health = 8 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 10);
	this->resistance = DAMAGE_TYPE::POISON;
}

Dwarf::~Dwarf()
{
	std::cout << "Dwarf destructor called" << endl;
}

void Dwarf::RollStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6) + 2;
	this->dexterity = RollDiceIgnoreLowest(4, 6);
	this->constitution = RollDiceIgnoreLowest(4, 6) + 2;
	this->intelligence = RollDiceIgnoreLowest(4, 6);
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6);
}

string Dwarf::GetRace()
{
	return this->race;
}
