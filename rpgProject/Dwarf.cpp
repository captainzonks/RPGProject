#include "Dwarf.h"

Dwarf::Dwarf()
{
	cout << "Dwarf constructor called" << endl; // debug
}

Dwarf::Dwarf(string name)
{
	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Dwarf";
	this->health = 100;
	this->xp = 0;
	this->rollStats();
	this->raceModification();
}

string Dwarf::getRace()
{
	return this->race;
}

void Dwarf::display()
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

void Dwarf::raceModification()
{
	this->strength += 2;
	this->constitution += 2;
	this->wisdom += 1;
}