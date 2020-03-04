#include "Dwarf.h"

Dwarf::Dwarf()
{
	cout << "Dwarf constructor called" << endl; // debug
}

Dwarf::Dwarf(int identifier)
{
	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Dwarf"; // temporary debug value
	this->identifier = identifier;
	this->race = "Dwarf";
	this->health = rollDice(1, 8) + getConstMod();
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Dwarf::Dwarf(string name)
{
	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->race = "Dwarf";
	this->health = rollDice(1, 8) + getConstMod();
	this->xp = 0;
	this->rollStats();
	this->myCurrency.addMoney(rollDice(4, 4), 0, 0);
}

Dwarf::~Dwarf()
{
	std::cout << "Dwarf destructor called" << endl;
}

void Dwarf::rollStats()
{
	this->strength = rollDiceIgnoreLowest(4, 6) + 2;
	this->dexterity = rollDiceIgnoreLowest(4, 6);
	this->constitution = rollDiceIgnoreLowest(4, 6) + 2;
	this->intelligence = rollDiceIgnoreLowest(4, 6);
	this->wisdom = rollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = rollDiceIgnoreLowest(4, 6);
}

void Dwarf::display()
{
	cout << endl;
	// name header
	cout << "====" << this->getName() << "====" << endl;
	// basic stats
	cout << "   " << this->getRace() << endl;
	cout << "   " << this->getHealth() << " HP" << endl;
	cout << "   " << (this->getArmorClass() + this->myInventory.GetArmorBonus()) << " AC" << endl;
	if (this->myInventory.HasWeapon())
		cout << "   " << "Has a sword!" << endl;
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

string Dwarf::getRace()
{
	return this->race;
}
