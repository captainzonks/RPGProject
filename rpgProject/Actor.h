#pragma once

#include "constants.h"
#include "helper_functions.h"
#include "menu.h"
#include "upgrades.h"
#include "inventory.h"
#include "currency.h"
#include "attack.h"
#include "potion.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Abstract Base Class

class actor
{
public:

	the_inventory_ myInventory;
	currency myCurrency;
	upgrades myUpgrades;

	// constructor
	actor();

	// destructors
	virtual ~actor();

	// setters
	virtual void roll_human_stats() = 0, roll_dwarf_stats() = 0, roll_elf_stats() = 0, roll_halfling_stats() = 0;

	// updaters
	virtual void update();
	virtual void update_armor_class();

	// getters
	virtual std::string get_name(), get_race();
	virtual int get_health(), get_armor_class(), get_xp(), get_level(), get_proficiency();
	virtual int get_strength(), get_dexterity(), get_constitution(), get_intelligence(), get_wisdom(), get_charisma();
	virtual int get_strength_mod(), get_dex_mod(), get_const_mod(), get_intel_mod(), get_wisdom_mod(), get_char_mod();
	virtual int get_passive_perception(), get_passive_insight(), get_passive_investigation();
	virtual damage_type get_resistance(), get_vulnerability();
	virtual int get_initiative();
	virtual bool is_alive(), is_dual_wielding(), is_two_handed_melee();
	virtual void display();
	virtual void update_average_item_level();
	virtual int get_average_item_level();
	virtual character_class get_combat_class();
	
	virtual int size_of_inventory();
	virtual void use_potion();

	// actions
	virtual void subtract_health(unsigned int damage);
	virtual void add_health(int healing);
	virtual void add_xp(int xpGain);
	virtual void check_level_up_threshold();
	virtual void level_up() = 0;

	// the_inventory_ management
	// virtual void openInventory();

	// armor related functions
	virtual void EquipHelmet(std::unique_ptr<Armor> helmet), EquipChest(std::unique_ptr<Armor> chest),
		EquipLegs(std::unique_ptr<Armor> legs), EquipHands(std::unique_ptr<Armor> hands),
		EquipBoots(std::unique_ptr<Armor> boots);

	// weaponL & shiled related functions
	virtual void EquipWeaponL(std::unique_ptr<Weapon> weaponL),
		EquipWeaponR(std::unique_ptr<Weapon> weaponR),
		EquipShield(std::unique_ptr<Armor> shield),
		EquipRanged(std::unique_ptr<Weapon> rangedWeapon);

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

	// fighter functions
	virtual fighting_style GetFightingStyle();

protected:
	// combat class
	character_class combatClass{ character_class::none };

	// basic traits
	std::string name;
	std::string race;
	int level_{ 1 };
	int max_health_{};
	int health{};
	int armorClass{ 10 };
	int proficiencyBonus{ 2 };
	int walkingSpeed{ 30 };
	int xp{};
	bool isAlive{ true };
	bool isDualWielding{ false };
	bool isTwoHanded{ false };
	damage_type resistance{ damage_type::none };
	damage_type vulnerability{ damage_type::none };

	// combat stuff
	int initiative{};
	int identifier{};
	int averageItemLevel{};

	// stats
	int strength{}, dexterity{}, constitution{}, intelligence{}, wisdom{}, charisma{};

	// fighter class things
	std::vector<abilities> savingThrows{ abilities::none };

	fighting_style fightingStyle{};
};

