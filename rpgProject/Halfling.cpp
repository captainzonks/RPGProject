#include "Halfling.h"

Halfling::Halfling()
{
	cout << "Halfling constructor called" << endl; // debug
}

Halfling::Halfling(int identifier)
{
	cout << "Halfling (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Halfling";
	this->identifier = identifier;
	this->race = "Halfling";
	this->health = 100;
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Halfling::Halfling(string name)
{
	cout << "Halfling (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Halfling";
	this->health = 100;
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Halfling::~Halfling()
{
	std::cout << "Halfling destructor called" << endl;
}

void Halfling::rollStats()
{
	this->strength = rollDiceIgnoreLowest(4, 6);
	this->dexterity = rollDiceIgnoreLowest(4, 6);
	this->constitution = rollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = rollDiceIgnoreLowest(4, 6);
	this->wisdom = rollDiceIgnoreLowest(4, 6);
	this->charisma = rollDiceIgnoreLowest(4, 6) + 1;
}

void Halfling::display()
{
	cout << endl;
	// name header
	cout << "====" << this->getName() << "====" << endl;
	// basic stats
	cout << "   " << this->getRace() << endl;
	cout << "   " << this->getHealth() << " HP" << endl;
	cout << "   " << this->getXP() << " XP" << endl;
	// ability stats
	cout << "   " << this->getStrength() << " Strength"
		<< " (" << this->getStrengthMod() << ")" << endl;
	cout << "   " << this->getDexterity() << " Dexterity"
		<< " (" << this->getDexMod() << ")" << endl;
	cout << "   " << this->getConstitution() << " Constitution"
		<< " (" << this->getConstMod() << ")" << endl;
	cout << "   " << this->getIntelligence() << " Intelligence"
		<< " (" << this->getIntelMod() << ")" << endl;
	cout << "   " << this->getWisdom() << " Wisdom"
		<< " (" << this->getWisdomMod() << ")" << endl;
	cout << "   " << this->getCharisma() << " Charisma"
		<< " (" << this->getCharMod() << ")" << endl;
	// footer (matches length of header plus name)
	cout << "====";
	for (char c : this->getName())
	{
		cout << "=";
	}
	cout << "====\n" << endl;
}

string Halfling::getRace()
{
	return this->race;
}
