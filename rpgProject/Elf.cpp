#include "Elf.h"

Elf::Elf()
{
	cout << "Elf constructor called" << endl; // debug
}

Elf::Elf(int identifier)
{
	cout << "Elf (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Elf";
	this->RollStats();
	this->identifier = identifier;
	this->race = "Elf";
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Elf::Elf(string name)
{
	cout << "Elf (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->RollStats();
	this->race = "Elf";
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Elf::~Elf()
{
	std::cout << "Elf destructor called" << endl;
}

void Elf::RollStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6);
	this->dexterity = RollDiceIgnoreLowest(4, 6) + 2;
	this->constitution = RollDiceIgnoreLowest(4, 6);
	this->intelligence = RollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

void Elf::Display()
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

string Elf::GetRace()
{
	return this->race;
}
