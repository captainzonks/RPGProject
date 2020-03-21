#pragma once

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
#include "Menu.h"

#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Inventory
{
public:
	friend class Actor;
	// constructor
	Inventory();

	// destructor
	~Inventory();

	void SetCapacity(int capacityChange);
	int GetCapacity() const;
	int TotalItemsInInventory() const;

	// weaponL functions
	void GetWeaponL(std::unique_ptr<Weapon> weaponL);
	void GetWeaponR(std::unique_ptr<Weapon> weaponR);
	bool HasWeapon();
	int GetAttackDiceL();
	int GetAttackDiceR();

	// armor functions
	void GetArmor(std::unique_ptr<Armor> armor);
	bool HasArmor();
	int GetArmorBonus();

	// inventory functions
	void AddToInventory(std::unique_ptr<Item> item);
	void AddPotionToInventory(std::unique_ptr<Potion> potion);
	void RemoveFromInventory(std::unique_ptr<Item> item);
	void RemovePotionFromInventory(std::unique_ptr<Potion> potion);
	void DisplayInventory() const;
	void DisplayPotions() const;
	std::unique_ptr<Item> GetItem(int itemNumber);
	std::unique_ptr<Potion> GetPotion(int itemNumber);
	
	// ammunition
	int ReturnAmmo();
	void SubtractAmmo();
	void AddAmmo(int amount);

	// Item* selectItemInInventory();

private:

	vector<std::unique_ptr<Item>> inventory{};
	vector<std::unique_ptr<Potion>> potionInventory{};
	bool hasWeaponL{ false };
	bool hasWeaponR{ false };
	bool hasArmor{ false };
	int attackDiceL{ 4 };
	int attackDiceR{ 4 };
	int armorBonus{};
	int capacity{ 10 };
	int ammunition{ 100 };
	int potionCapacity{ 5 };

};
