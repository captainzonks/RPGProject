#include "Human.h"

Human::Human()
{
	cout << "Human constructor called" << endl; // debug
}

Human::Human(int identifier)
{
	cout << "Human (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Human"; // temporary debug
	this->identifier = identifier;
	this->race = "Human";
	this->health = rollDice(1, 8);
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Human::Human(string name)
{
	cout << "Human (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Human";
	this->health = rollDice(1, 8);
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Human::~Human()
{
	std::cout << "Human destructor called" << endl;
}

void Human::rollStats()
{
	this->strength = rollDiceIgnoreLowest(4, 6) + 1;
	this->dexterity = rollDiceIgnoreLowest(4, 6) + 1;
	this->constitution = rollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = rollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = rollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = rollDiceIgnoreLowest(4, 6) + 1;
}

void Human::display()
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

string Human::getRace()
{
	return this->race;
}
