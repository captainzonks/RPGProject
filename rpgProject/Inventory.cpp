#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	this->inventory.clear();
	cout << "Inventory destructor called" << endl;
}

void Inventory::setCapacity(int capacityChange)
{
	this->capacity += capacityChange;
}

int Inventory::getCapacity() const
{
	return this->capacity;
}

int Inventory::totalItemsInInventory() const
{
	return this->inventory.size();
}

void Inventory::addToInventory(std::unique_ptr<Item> item)
{
	this->inventory.push_back(std::move(item));
}

void Inventory::displayInventory() const
{
	cout << "============" << endl;
	int counter{ 1 };
	for (auto& i : this->inventory)
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
