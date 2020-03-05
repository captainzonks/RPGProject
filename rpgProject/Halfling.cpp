#include "Halfling.h"

Halfling::Halfling()
{
	cout << "Halfling constructor called" << endl; // debug
}

Halfling::Halfling(int identifier)
{
	cout << "Halfling (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Halfling";
	this->RollStats();
	this->identifier = identifier;
	this->race = "Halfling";
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Halfling::Halfling(string name)
{
	cout << "Halfling (name) overloaded constructor called" << endl; // debug
	this->name = name;
	this->RollStats();
	this->race = "Halfling";
	this->health = 6 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Halfling::~Halfling()
{
	std::cout << "Halfling destructor called" << endl;
}

void Halfling::RollStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6);
	this->dexterity = RollDiceIgnoreLowest(4, 6);
	this->constitution = RollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = RollDiceIgnoreLowest(4, 6);
	this->wisdom = RollDiceIgnoreLowest(4, 6);
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

void Halfling::Display()
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

string Halfling::GetRace()
{
	return this->race;
}
