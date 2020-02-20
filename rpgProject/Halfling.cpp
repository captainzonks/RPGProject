#include "Halfling.h"

Halfling::Halfling()
{
	cout << "Halfling constructor called" << endl; // debug
}

Halfling::Halfling(string name)
{
	cout << "Halfling (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Halfling";
	this->health = 100;
	this->xp = 0;
	this->rollStats();
	this->raceModification();
}

string Halfling::getRace()
{
	return this->race;
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

void Halfling::raceModification()
{
	this->constitution += 1;
	this->charisma += 1;
}