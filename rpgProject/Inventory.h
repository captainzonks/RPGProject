#pragma once

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
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

	// weapon functions
	void GetWeapon(std::unique_ptr<Weapon> weapon);
	bool HasWeapon();
	int GetAttackDice();

	// armor functions
	void GetArmor(std::unique_ptr<Armor> armor);
	bool HasArmor();
	int GetArmorBonus();

	// inventory functions
	void AddToInventory(std::unique_ptr<Item> item);
	void DisplayInventory() const;



	// Item* selectItemInInventory();

private:

	vector<std::unique_ptr<Item>> inventory{};
	bool hasWeapon{ false };
	bool hasArmor{ false };
	int attackDice{ 4 };
	int armorBonus{};
	int capacity{ 10 };

};
