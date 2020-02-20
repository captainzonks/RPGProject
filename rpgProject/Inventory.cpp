#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	for (auto i : inventory)
		delete i;
	inventory.clear();
	cout << "Inventory destructor called" << endl;
}

int Inventory::getCapacity()
{
	return capacity;
}

void Inventory::addToInventory(Item* item)
{
	this->inventory.push_back(item);
}

void Inventory::displayInventory()
{
	cout << "============" << endl;
	int counter{ 1 };
	for (auto i : this->inventory)
	{
		cout << counter << ": " << *i << endl;
	}
	cout << "============" << endl;
}