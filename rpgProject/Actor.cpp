#include "Actor.h"

Actor::Actor()
{
	cout << "\nActor constructor called" << endl; // debug
	this->name = "Guy";
	this->health = 8;
	this->maxHealth = health;
	this->xp = 0;
	this->strength = 0;
	this->dexterity = 0;
	this->constitution = 0;
	this->intelligence = 0;
	this->wisdom = 0;
	this->charisma = 0;
}

Actor::~Actor()
{
}

//void Actor::RollStats()
//{
//	this->strength = RollDiceIgnoreLowest(4, 6);
//	this->dexterity = RollDiceIgnoreLowest(4, 6);
//	this->constitution = RollDiceIgnoreLowest(4, 6);
//	this->intelligence = RollDiceIgnoreLowest(4, 6);
//	this->wisdom = RollDiceIgnoreLowest(4, 6);
//	this->charisma = RollDiceIgnoreLowest(4, 6);
//}

void Actor::SetArmorClass(int armor)
{
	armorClass += armor;
}

string Actor::GetName()
{
	return this->name;
}

string Actor::GetRace()
{
	return this->race;
}

int Actor::GetHealth()
{
	return this->health;
}

int Actor::GetXP()
{
	return this->xp;
}

int Actor::GetArmorClass()
{
	return this->armorClass;
}

int Actor::GetStrength()
{
	return this->strength;
}

int Actor::GetDexterity()
{
	return this->dexterity;
}

int Actor::GetConstitution()
{
	return this->constitution;
}

int Actor::GetIntelligence()
{
	return this->intelligence;
}

int Actor::GetWisdom()
{
	return this->wisdom;
}

int Actor::GetCharisma()
{
	return this->charisma;
}

int Actor::GetStrengthMod()
{
	int mod{ (this->strength - 10) / 2 };
	return mod;
}

int Actor::GetDexMod()
{
	int mod{ (this->dexterity - 10) / 2 };
	return mod;
}

int Actor::GetConstMod()
{
	int mod{ (this->constitution - 10) / 2 };
	return mod;
}

int Actor::GetIntelMod()
{
	int mod{ (this->intelligence - 10) / 2 };
	return mod;
}

int Actor::GetWisdomMod()
{
	int mod{ (this->wisdom - 10) / 2 };
	return mod;
}

int Actor::GetCharMod()
{
	int mod{ (this->charisma - 10) / 2 };
	return mod;
}

int Actor::getPassiveInsight()
{
	int passiveInsight{ 10 + this->GetWisdomMod() };
	return passiveInsight;
}

int Actor::getPassivePercetion()
{
	int passivePerception{ 10 + this->GetWisdomMod() };
	return passivePerception;
}

int Actor::getPassiveInvestigation()
{
	int passiveInvestigation{ 10 + this->GetIntelMod() };
	return passiveInvestigation;
}

int Actor::GetInitiative()
{
	return initiative;
}

bool Actor::LivingOrDead()
{
	return isAlive;
}

//void Actor::Display()
//{
//	cout << endl;
//	// name header
//	cout << "====" << this->GetName() << "====" << endl;
//	// basic stats
//	cout << "   " << this->GetHealth() << " HP" << endl;
//	cout << "   " << this->GetXP() << " XP" << endl;
//	// ability stats
//	cout << "   " << this->GetStrength() << " Strength"
//		<< " (" << this->GetStrengthMod() << ")" << endl;
//	cout << "   " << this->GetDexterity() << " Dexterity"
//		<< " (" << this->GetDexMod() << ")" << endl;
//	cout << "   " << this->GetConstitution() << " Constitution"
//		<< " (" << this->getConstMod() << ")" << endl;
//	cout << "   " << this->GetIntelligence() << " Intelligence"
//		<< " (" << this->GetIntelMod() << ")" << endl;
//	cout << "   " << this->GetWisdom() << " Wisdom"
//		<< " (" << this->GetWisdomMod() << ")" << endl;
//	cout << "   " << this->GetCharisma() << " Charisma"
//		<< " (" << this->GetCharMod() << ")" << endl;
//	// footer (matches length of header plus name)
//	cout << "====";
//	for (char c : this->GetName())
//	{
//		cout << "=";
//	}
//	cout << "====\n" << endl;
//}


int Actor::SizeOfInventory()
{
	return this->myInventory.GetCapacity();
}

void Actor::SubtractHealth(int& damage)
{
	this->health -= damage;
	if (health <= 0)
		isAlive = false;
}

void Actor::AddXP(int xpGain)
{
	this->xp += xpGain;
}

//void Actor::openInventory()
//{
//	myInventory.displayInventory();
//	
//	Menu* tempMenu = new Menu;
//	const int* decisions = new int{ 2 };
//	vector<string>* decisionList = new vector<string>{ "Equip Armor", "Exit" };
//
//	if (tempMenu->PrintMenu(*decisions, *decisionList) == 1)
//	{
//		EquipArmor(myInventory.selectItemInInventory());
//	}
//}

void Actor::EquipArmor(Armor& armor)
{
	SetArmorClass(armor.GetArmorValue());
}

void Actor::ModifyStrength(const int& modifier)
{
	this->strength += modifier;
}

void Actor::ModifyDexterity(const int& modifier)
{
	this->dexterity += modifier;
}

void Actor::ModifyConstitution(const int& modifier)
{
	this->constitution += modifier;
}

void Actor::ModifyIntelligence(const int& modifier)
{
	this->intelligence += modifier;
}

void Actor::ModifyWisdom(const int& modifier)
{
	this->wisdom += modifier;
}

void Actor::ModifyCharisma(const int& modifier)
{
	this->charisma += modifier;
}

void Actor::RollForInitiative()
{
	initiative = RollDice(1, 20) + this->GetDexMod();
}

void Actor::ClearInitiative()
{
	this->initiative = 0;
}

//void Actor::attack(Actor& target)
//{
//	// TODO this is a basic randomly generated attack concept
//	// eventual goal is to have unique attacks in separate methods (or classes)
//	int tempQuantity{ 1 }; // debug purposes
//	cout << this->name << " is attacking " << target.name << endl;
//	int damage{ RollDice(tempQuantity, attackDice) };
//	if (target.SubtractHealth(damage))
//	{
//		cout << this->name << " did " << damage << " damage to " << target.name << "!" << endl;
//	}
//	else if (!target.SubtractHealth(damage))
//	{
//		cout << this->name << " killed " << target.name << " with " << damage << " damage!" << endl;
//		target.isAlive = false;
//	}
//}