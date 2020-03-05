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

void Inventory::GetWeapon(std::unique_ptr<Weapon> weapon)
{
	hasWeapon = true;
	attackDice = weapon->getAttackDie();
	addToInventory(std::move(weapon));
}

void Inventory::addToInventory(std::unique_ptr<Item> item)
{
	if (capacity > 0)
	{
		this->inventory.push_back(std::move(item));
		capacity--;
	}
	else
		std::cout << "You don't have enough room!" << std::endl;
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

bool Inventory::HasWeapon()
{
	return hasWeapon;
}

int Inventory::GetAttackDice()
{
	return attackDice;
}

void Inventory::GetArmor(std::unique_ptr<Armor> armor)
{
	hasArmor = true;
	armorBonus += armor->getArmorValue();
	addToInventory(std::move(armor));
}

bool Inventory::HasArmor()
{
	return hasArmor;
}

int Inventory::GetArmorBonus()
{
	return armorBonus;
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
