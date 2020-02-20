#pragma once

#include "Sword.h"

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

class Inventory
{
public:
	friend class Actor;

	Inventory();

	~Inventory();

	int getCapacity();

	void addToInventory(Item* item);
	void displayInventory();

private:

	vector<Item*> inventory{};

	int capacity{ 10 };

};
