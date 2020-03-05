#include "Human.h"

Human::Human()
{
	cout << "Human constructor called" << endl; // debug
}

Human::Human(int identifier)
{
	cout << "Human (int identifier) overloaded constructor called" << endl; // debug
	this->name = "Bad Guy Human"; // temporary debug
	this->RollStats();
	this->identifier = identifier;
	this->race = "Human";
	this->health = 8 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Human::Human(string name)
{
	cout << "Human (name) overloaded constructor called" << endl; // debug
	this->RollStats();
	this->name = name;
	this->race = "Human";
	this->health = 8 + GetConstMod();
	this->maxHealth = health;
	this->xp = 0;
	this->myCurrency.AddMoney(RollDice(4, 4) * 100);
}

Human::~Human()
{
	std::cout << "Human destructor called" << endl;
}

void Human::RollStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6) + 1;
	this->dexterity = RollDiceIgnoreLowest(4, 6) + 1;
	this->constitution = RollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = RollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

void Human::Display()
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

string Human::GetRace()
{
	return this->race;
}