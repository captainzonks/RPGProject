//#include "Human.h"
//
//Human::Human()
//{
//	cout << "Human constructor called" << endl; // debug
//}
//
//Human::Human(int identifier)
//{
//	cout << "Human (int identifier) overloaded constructor called" << endl; // debug
//	this->name = "Bad Guy Human"; // temporary debug
//	this->RollStats();
//	this->identifier = identifier;
//	this->race = "Human";
//	this->level = 1;
//	this->health = 8 + GetConstMod();
//	this->maxHealth = health;
//	this->xp = 0;
//	this->myCurrency.AddMoney(RollDice(4, 4) * 10);
//}
//
//Human::Human(string name)
//{
//	cout << "Human (name) overloaded constructor called" << endl; // debug
//	this->RollStats();
//	this->name = name;
//	this->race = "Human";
//	this->level = 1;
//	this->health = 8 + GetConstMod();
//	this->maxHealth = health;
//	this->xp = 0;
//	this->myCurrency.AddMoney(RollDice(4, 4) * 10);
//}
//
//Human::~Human()
//{
//	std::cout << "Human destructor called" << endl;
//}
//
//void Human::RollStats()
//{
//	this->strength = RollDiceIgnoreLowest(4, 6) + 1;
//	this->dexterity = RollDiceIgnoreLowest(4, 6) + 1;
//	this->constitution = RollDiceIgnoreLowest(4, 6) + 1;
//	this->intelligence = RollDiceIgnoreLowest(4, 6) + 1;
//	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
//	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
//}
//
//string Human::GetRace()
//{
//	return this->race;
//}