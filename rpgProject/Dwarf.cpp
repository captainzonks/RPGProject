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
	this->health = 8 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Dwarf::Dwarf(string name)
{
	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->RollStats();
	this->race = "Dwarf";
	this->health = 8 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
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

void Dwarf::Display()
{
	cout << endl;
	// name header
	cout << "====" << this->GetName() << "====" << endl;
	// basic stats
	cout << "   " << this->GetRace() << endl;
	cout << "   " << this->GetHealth() << " HP" << endl;
	cout << "   " << (this->GetArmorClass() + this->myInventory.GetArmorBonus()) << " AC" << endl;
	if (this->myInventory.HasWeapon())
		cout << "   " << "Has a sword!" << endl;
	cout << "   " << this->GetXP() << " XP" << endl;
	// ability stats
	cout << "   " << this->GetStrength() << " Strength"
		<< " (" << this->GetStrengthMod() << ")" << endl;
	cout << "   " << this->GetDexterity() << " Dexterity"
		<< " (" << this->GetDexMod() << ")" << endl;
	cout << "   " << this->GetConstitution() << " Constitution"
		<< " (" << this->GetConstMod() << ")" << endl;
	cout << "   " << this->GetIntelligence() << " Intelligence"
		<< " (" << this->GetIntelMod() << ")" << endl;
	cout << "   " << this->GetWisdom() << " Wisdom"
		<< " (" << this->GetWisdomMod() << ")" << endl;
	cout << "   " << this->GetCharisma() << " Charisma"
		<< " (" << this->GetCharMod() << ")" << endl;
	// footer (matches length of header plus name)
	cout << "====";
	for (char c : this->GetName())
	{
		cout << "=";
	}
	cout << "====\n" << endl;
}

string Dwarf::GetRace()
{
	return this->race;
}
