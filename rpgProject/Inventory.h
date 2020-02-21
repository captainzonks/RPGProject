#pragma once

#include "Item.h"
#include "Armor.h"
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

	Inventory();

	~Inventory();

	void setCapacity(int capacityChange);
	int getCapacity();
	int totalItemsInInventory();

	void addToInventory(Item* item);
	void displayInventory();

	// Item* selectItemInInventory();

private:

	vector<Item*> inventory{};

	int capacity{ 10 };

};
