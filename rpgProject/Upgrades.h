#pragma once

#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Helmet.h"
#include "Chest.h"
#include "Legs.h"
#include "Hands.h"
#include "Boots.h"
#include "Sword.h"
#include "ShortBow.h"
#include "Shield.h"

class upgrades
{
public:
	// constructor
	upgrades();

	// destructor
	~upgrades();

	// pointers
	std::unique_ptr<Weapon> weaponL{ nullptr };
	std::unique_ptr<Weapon> weaponR{ nullptr };
	std::unique_ptr<Weapon> rangedWeapon{ nullptr };
	std::unique_ptr<Armor> shield{ nullptr };

	std::unique_ptr<Armor> helmet{ nullptr };
	std::unique_ptr<Armor> chest{ nullptr };
	std::unique_ptr<Armor> legs{ nullptr };
	std::unique_ptr<Armor> hands{ nullptr };
	std::unique_ptr<Armor> boots{ nullptr };

	// display
	void DisplayUpgrades();

	// updaters
	int TotalArmorValue();

	// armor getters
	bool HelmetEquipped(), ChestEquipped(), LegsEquipped(), HandsEquipped(), BootsEquipped();
	int GetHelmetLevel(), GetChestLevel(), GetLegsLevel(), GetHandsLevel(), GetBootsLevel();

	// weapon getters
	bool IsDualWielding(), IsRangedWeapon();
	bool WeaponLEquipped(), WeaponREquipped(), RangedWeaponEquipped(), ShieldEquipped();
	int GetWeaponLLevel(), GetWeaponRLevel(), GetRangedWeaponLevel(), GetShieldLevel();
	int GetAttackDieWeaponL(), GetAttackDieWeaponR(), GetRangedAttackDie();
	damage_type GetAttackDamageTypeWeaponL(), GetAttackDamageTypeWeaponR(), GetRangedAttackDamageType();

	// weapon setter
	void EquipWeaponL(std::unique_ptr<Weapon> weaponL);
	void EquipWeaponR(std::unique_ptr<Weapon> weaponR);
	void EquipRangedWeapon(std::unique_ptr<Weapon> rangedWeapon);
	void UnequipWeaponL(), UnequipWeaponR(), UnequipRangedWeapon();

	// shield setter
	void EquipShield(std::unique_ptr<Armor> shield);
	void UnequipShield();

	// armor setters
	void EquipHelmet(std::unique_ptr<Armor> helmet), EquipChest(std::unique_ptr<Armor> chest), 
		EquipLegs(std::unique_ptr<Armor> legs), EquipHands(std::unique_ptr<Armor> hands), 
		EquipBoots(std::unique_ptr<Armor> boots);
	void UnequipHelmet(), UnequipChest(), UnequipLegs(), UnequipHands(), UnequipBoots();

	// nothing getter
	bool IsAnythingEquipped();

private:
	// initial null
	bool nothingEquipped{ true };

	// armor booleans
	bool hasHelmet{ false };
	bool hasChest{ false };
	bool hasLegs{ false };
	bool hasHands{ false };
	bool hasBoots{ false };

	// weapon & shield booleans
	bool isDualWielding{ false };
	bool hasRangedWeapon{ false };
	bool hasWeaponL{ false };
	bool hasWeaponR{ false };
	bool hasShield{ false };

	int unarmedAttackDie{ 4 };
};

