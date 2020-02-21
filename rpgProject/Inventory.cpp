#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	for (auto i : this->inventory)
		delete i;
	this->inventory.clear();
	cout << "Inventory destructor called" << endl;
}

void Inventory::setCapacity(int capacityChange)
{
	this->capacity += capacityChange;
}

int Inventory::getCapacity()
{
	return this->capacity;
}

int Inventory::totalItemsInInventory()
{
	return this->inventory.size();
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
		counter++;
	}
	cout << "============" << endl;
}

//Item* Inventory::selectItemInInventory()
//{
//	Menu* tempMenu = new Menu;
//	const int* decisions = new int{ totalItemsInInventory() };
//
//	Item* item_ptr = this->inventory[tempMenu->choiceHandler(*decisions)];
//
//	delete decisions, tempMenu;
//
//	return item_ptr;
//}
