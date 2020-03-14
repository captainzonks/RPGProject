#pragma once

#include "Constants.h"
#include "HelperFunctions.h"
#include "Menu.h"
#include "Upgrades.h"
#include "Inventory.h"
#include "Currency.h"
#include "Attack.h"
#include "Potion.h"

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
	Upgrades myUpgrades;

	// constructor
	Actor();

	// destructors
	virtual ~Actor();

	// setters
	virtual void RollHumanStats() = 0, RollDwarfStats() = 0, RollElfStats() = 0, RollHalflingStats() = 0;

	// updaters
	virtual void Update();
	virtual void UpdateArmorClass();

	// getters
	virtual string GetName(), GetRace();
	virtual int GetHealth(), GetArmorClass(), GetXP(), GetLevel(), GetProficiency();
	virtual int GetStrength(), GetDexterity(), GetConstitution(), GetIntelligence(), GetWisdom(), GetCharisma();
	virtual int GetStrengthMod(), GetDexMod(), GetConstMod(), GetIntelMod(), GetWisdomMod(), GetCharMod();
	virtual int GetPassivePerception(), GetPassiveInsight(), GetPassiveInvestigation();
	virtual DAMAGE_TYPE GetResistance(), GetVulnerability();
	virtual int GetInitiative();
	virtual bool LivingOrDead();
	virtual void Display();
	virtual void UpdateAverageItemLevel();
	virtual int GetAverageItemLevel();
	
	virtual int SizeOfInventory();
	virtual void UsePotion();

	// actions
	virtual void SubtractHealth(int& damage);
	virtual void AddHealth(int healing);
	virtual void AddXP(int xpGain);
	virtual void CheckLevelUpThreshold();
	virtual void LevelUp() = 0;

	// inventory management
	// virtual void openInventory();

	// armor related functions
	virtual void EquipHelmet(std::unique_ptr<Armor> helmet), EquipChest(std::unique_ptr<Armor> chest),
		EquipLegs(std::unique_ptr<Armor> legs), EquipHands(std::unique_ptr<Armor> hands),
		EquipBoots(std::unique_ptr<Armor> boots);

	// weapon & shiled related functions
	virtual void EquipWeapon(std::unique_ptr<Weapon> weapon), 
		EquipShield(std::unique_ptr<Armor> shield);

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

	// combatclass related virtual functions
	virtual void DisplayClassInformation() = 0;

protected:
	// friend class Narrator;

	// basic traits
	string name;
	string race;
	int level{ 1 };
	int maxHealth{};
	int health{};
	int armorClass{ 10 };
	int proficiencyBonus{ 2 };
	int walkingSpeed{ 30 };
	int xp{};
	bool isAlive{ true };
	DAMAGE_TYPE resistance{ DAMAGE_TYPE::NONE };
	DAMAGE_TYPE vulnerability{ DAMAGE_TYPE::NONE };

	int initiative{};
	int identifier{};
	int averageItemLevel{};

	// stats
	int strength{}, dexterity{}, constitution{}, intelligence{}, wisdom{}, charisma{};
};

