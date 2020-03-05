#pragma once

#include "HelperFunctions.h"
#include "Menu.h"
#include "Inventory.h"
#include "Currency.h"
#include "Attack.h"

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
	virtual void RollStats() = 0;
	virtual void SetArmorClass(int armor);

	// getters
	virtual string GetName(), GetRace();
	virtual int GetHealth(), GetArmorClass(), GetXP();
	virtual int GetStrength(), GetDexterity(), GetConstitution(), GetIntelligence(), GetWisdom(), GetCharisma();
	virtual int GetStrengthMod(), GetDexMod(), GetConstMod(), GetIntelMod(), GetWisdomMod(), GetCharMod();
	virtual int getPassivePercetion(), getPassiveInsight(), getPassiveInvestigation();
	virtual int GetInitiative();
	virtual bool LivingOrDead();
	virtual void Display() = 0;
	
	virtual int SizeOfInventory();

	// actions
	virtual void SubtractHealth(int& damage);
	virtual void AddXP(int xpGain);

	// inventory management
	// virtual void openInventory();

	// armor related functions
	virtual void EquipArmor(Armor& armor);

	// modify stats
	virtual void ModifyStrength(const int& modifier),
		ModifyDexterity(const int& modifier),
		ModifyConstitution(const int& modifier),
		ModifyIntelligence(const int& modifier),
		ModifyWisdom(const int& modifier),
		ModifyCharisma(const int& modifier);

	// combat
	virtual void RollForInitiative();
	virtual void ClearInitiative();

protected:
	// friend class Narrator;

	// basic traits
	string name;
	string race;
	int maxHealth{};
	int health{};
	int armorClass{ 10 };
	int walkingSpeed{ 30 };
	int xp{};
	bool isAlive{ true };

	int initiative{};
	int identifier{};

	// stats
	int strength, dexterity, constitution, intelligence, wisdom, charisma;
};

