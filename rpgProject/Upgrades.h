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
#include "Shield.h"

class Upgrades
{
public:
	// constructor
	Upgrades();

	// destructor
	~Upgrades();

	// pointers
	std::unique_ptr<Weapon> weapon{ nullptr };
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
	bool WeaponEquipped(), ShieldEquipped();
	int GetWeaponLevel(), GetShieldLevel();
	int GetAttackDie();
	DAMAGE_TYPE GetAttackDamageType();

	// weapon setter
	void EquipWeapon(std::unique_ptr<Weapon> weapon);
	void UnequipWeapon();

	// shield setter
	void EquipShield(std::unique_ptr<Armor> shield);
	void UnequipShield();

	// armor setters
	void EquipHelmet(std::unique_ptr<Armor> helmet), EquipChest(std::unique_ptr<Armor> chest), 
		EquipLegs(std::unique_ptr<Armor> legs), EquipHands(std::unique_ptr<Armor> hands), 
		EquipBoots(std::unique_ptr<Armor> boots);
	void UnequipHelmet(), UnequipChest(), UnequipLegs(), UnequipHands(), UnequipBoots();

private:
	// armor booleans
	bool hasHelmet{ false };
	bool hasChest{ false };
	bool hasLegs{ false };
	bool hasHands{ false };
	bool hasBoots{ false };

	// weapon & shield booleans
	bool hasWeapon{ false };
	bool hasShield{ false };

	int unarmedAttackDie{ 4 };
};

