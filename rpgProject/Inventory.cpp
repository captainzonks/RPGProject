#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	this->inventory.clear();
	cout << "Inventory destructor called" << endl;
}

void Inventory::SetCapacity(int capacityChange)
{
	this->capacity += capacityChange;
}

int Inventory::GetCapacity() const
{
	return this->capacity;
}

int Inventory::TotalItemsInInventory() const
{
	return this->inventory.size();
}

void Inventory::GetWeapon(std::unique_ptr<Weapon> weapon)
{
	hasWeapon = true;
	attackDice = weapon->GetAttackDie();
	AddToInventory(std::move(weapon));
}

void Inventory::AddToInventory(std::unique_ptr<Item> item)
{
	if (capacity > 0)
	{
		this->inventory.push_back(std::move(item));
		capacity--;
	}
	else
		std::cout << "You don't have enough room!" << std::endl;
}

void Inventory::DisplayInventory() const
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
	// need to separate out armor and shield...
	if (!hasArmor)
	{
		hasArmor = true;
		armorBonus += armor->GetArmorValue();
		AddToInventory(std::move(armor));
	}
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
