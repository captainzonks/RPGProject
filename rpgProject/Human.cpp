#include "Human.h"

Human::Human()
{
	cout << "Human constructor called" << endl; // debug
}

Human::Human(string name)
{
	cout << "Human (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Human";
	this->health = 100;
	this->xp = 0;
	this->rollStats();
	this->raceModification();
}

Human::~Human()
{
}

string Human::getRace()
{
	return this->race;
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

void Human::raceModification()
{
	this->strength += 1;
	this->dexterity += 1;
	this->constitution += 1;
	this->intelligence += 1;
	this->wisdom += 1;
	this->charisma += 1;
}