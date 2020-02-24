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

	// constructor
	Inventory();

	// destructor
	~Inventory();

	void setCapacity(int capacityChange);
	int getCapacity() const;
	int totalItemsInInventory() const;

	void addToInventory(std::unique_ptr<Item> item);
	void displayInventory() const;

	// Item* selectItemInInventory();

private:

	vector<std::unique_ptr<Item>> inventory{};

	int capacity{ 10 };

};
