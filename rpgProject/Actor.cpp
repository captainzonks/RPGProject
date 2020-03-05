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

//void Actor::rollStats()
//{
//	this->strength = rollDiceIgnoreLowest(4, 6);
//	this->dexterity = rollDiceIgnoreLowest(4, 6);
//	this->constitution = rollDiceIgnoreLowest(4, 6);
//	this->intelligence = rollDiceIgnoreLowest(4, 6);
//	this->wisdom = rollDiceIgnoreLowest(4, 6);
//	this->charisma = rollDiceIgnoreLowest(4, 6);
//}

void Actor::setArmorClass(int armor)
{
	armorClass += armor;
}

string Actor::getName()
{
	return this->name;
}

string Actor::getRace()
{
	return this->race;
}

int Actor::getHealth()
{
	return this->health;
}

int Actor::getXP()
{
	return this->xp;
}

int Actor::getArmorClass()
{
	return this->armorClass;
}

int Actor::getStrength()
{
	return this->strength;
}

int Actor::getDexterity()
{
	return this->dexterity;
}

int Actor::getConstitution()
{
	return this->constitution;
}

int Actor::getIntelligence()
{
	return this->intelligence;
}

int Actor::getWisdom()
{
	return this->wisdom;
}

int Actor::getCharisma()
{
	return this->charisma;
}

int Actor::getStrengthMod()
{
	int mod{ (this->strength - 10) / 2 };
	return mod;
}

int Actor::getDexMod()
{
	int mod{ (this->dexterity - 10) / 2 };
	return mod;
}

int Actor::getConstMod()
{
	int mod{ (this->constitution - 10) / 2 };
	return mod;
}

int Actor::getIntelMod()
{
	int mod{ (this->intelligence - 10) / 2 };
	return mod;
}

int Actor::getWisdomMod()
{
	int mod{ (this->wisdom - 10) / 2 };
	return mod;
}

int Actor::getCharMod()
{
	int mod{ (this->charisma - 10) / 2 };
	return mod;
}

int Actor::getPassiveInsight()
{
	int passiveInsight{ 10 + this->getWisdomMod() };
	return passiveInsight;
}

int Actor::getPassivePercetion()
{
	int passivePerception{ 10 + this->getWisdomMod() };
	return passivePerception;
}

int Actor::getPassiveInvestigation()
{
	int passiveInvestigation{ 10 + this->getIntelMod() };
	return passiveInvestigation;
}

int Actor::GetInitiative()
{
	return initiative;
}

bool Actor::livingOrDead()
{
	return isAlive;
}

//void Actor::display()
//{
//	cout << endl;
//	// name header
//	cout << "====" << this->getName() << "====" << endl;
//	// basic stats
//	cout << "   " << this->getHealth() << " HP" << endl;
//	cout << "   " << this->getXP() << " XP" << endl;
//	// ability stats
//	cout << "   " << this->getStrength() << " Strength"
//		<< " (" << this->getStrengthMod() << ")" << endl;
//	cout << "   " << this->getDexterity() << " Dexterity"
//		<< " (" << this->getDexMod() << ")" << endl;
//	cout << "   " << this->getConstitution() << " Constitution"
//		<< " (" << this->getConstMod() << ")" << endl;
//	cout << "   " << this->getIntelligence() << " Intelligence"
//		<< " (" << this->getIntelMod() << ")" << endl;
//	cout << "   " << this->getWisdom() << " Wisdom"
//		<< " (" << this->getWisdomMod() << ")" << endl;
//	cout << "   " << this->getCharisma() << " Charisma"
//		<< " (" << this->getCharMod() << ")" << endl;
//	// footer (matches length of header plus name)
//	cout << "====";
//	for (char c : this->getName())
//	{
//		cout << "=";
//	}
//	cout << "====\n" << endl;
//}


int Actor::sizeOfInventory()
{
	return this->myInventory.getCapacity();
}

void Actor::subtractHealth(int& damage)
{
	this->health -= damage;
	if (health <= 0)
		isAlive = false;
}

void Actor::addXP(int xpGain)
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
//	if (tempMenu->printMenu(*decisions, *decisionList) == 1)
//	{
//		equipArmor(myInventory.selectItemInInventory());
//	}
//}

void Actor::equipArmor(Armor& armor)
{
	setArmorClass(armor.getArmorValue());
}

void Actor::modifyStrength(const int& modifier)
{
	this->strength += modifier;
}

void Actor::modifyDexterity(const int& modifier)
{
	this->dexterity += modifier;
}

void Actor::modifyConstitution(const int& modifier)
{
	this->constitution += modifier;
}

void Actor::modifyIntelligence(const int& modifier)
{
	this->intelligence += modifier;
}

void Actor::modifyWisdom(const int& modifier)
{
	this->wisdom += modifier;
}

void Actor::modifyCharisma(const int& modifier)
{
	this->charisma += modifier;
}

void Actor::RollForInitiative()
{
	initiative = rollDice(1, 20) + this->getDexMod();
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
//	int damage{ rollDice(tempQuantity, attackDice) };
//	if (target.subtractHealth(damage))
//	{
//		cout << this->name << " did " << damage << " damage to " << target.name << "!" << endl;
//	}
//	else if (!target.subtractHealth(damage))
//	{
//		cout << this->name << " killed " << target.name << " with " << damage << " damage!" << endl;
//		target.isAlive = false;
//	}
//}