#pragma once

#include "Menu.h"
#include "Inventory.h"
#include "Currency.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Abstract Base Class

class Actor
{
public:

	Inventory myInventory;
	Currency myCurrency;

	// constructors
	Actor();

	// destructors
	virtual ~Actor();

	// setters
	virtual void rollStats() = 0;
	virtual void setArmorClass(int armor);

	// getters
	virtual string getName(), getRace();
	virtual int getHealth(), getArmorClass(), getXP();
	virtual int getStrength(), getDexterity(), getConstitution(), getIntelligence(), getWisdom(), getCharisma();
	virtual int getStrengthMod(), getDexMod(), getConstMod(), getIntelMod(), getWisdomMod(), getCharMod();
	virtual int getPassivePercetion(), getPassiveInsight(), getPassiveInvestigation();
	virtual bool livingOrDead();
	virtual void display() = 0;
	
	virtual int sizeOfInventory();

	// actions
	virtual bool subtractHealth(int& damage);
	virtual void addXP(int& xpGain);
	virtual int rollDice(const int& quantity, const int& dice),
		rollDiceIgnoreLowest(const int& quantity, const int& dice);

	// inventory management
	// virtual void openInventory();

	// armor related functions
	virtual void equipArmor(Armor& armor);

	// modify stats
	virtual void modifyStrength(const int& modifier),
		modifyDexterity(const int& modifier),
		modifyConstitution(const int& modifier),
		modifyIntelligence(const int& modifier),
		modifyWisdom(const int& modifier),
		modifyCharisma(const int& modifier);

	// moves (temporary)
	/*virtual void attack(Actor& target);*/

protected:
	// friend class Narrator;

	// basic traits
	string name;
	string race;
	int health;
	int armorClass{ 10 };
	int walkingSpeed{ 30 };
	int xp;
	bool isAlive{ true };

	int identifier{};

	// stats
	int strength, dexterity, constitution, intelligence, wisdom, charisma;
};

