#include "Elf.h"

Elf::Elf()
{
	cout << "Elf constructor called" << endl; // debug
}

Elf::Elf(int identifier)
{
	cout << "Elf (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Elf";
	this->identifier = identifier;
	this->race = "Elf";
	this->health = rollDice(1, 6);
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Elf::Elf(string name)
{
	cout << "Elf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Elf";
	this->health = rollDice(1, 6);
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Elf::~Elf()
{
	std::cout << "Elf destructor called" << endl;
}

void Elf::rollStats()
{
	this->strength = rollDiceIgnoreLowest(4, 6);
	this->dexterity = rollDiceIgnoreLowest(4, 6) + 2;
	this->constitution = rollDiceIgnoreLowest(4, 6);
	this->intelligence = rollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = rollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = rollDiceIgnoreLowest(4, 6) + 1;
}

void Elf::display()
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

string Elf::getRace()
{
	return this->race;
}
