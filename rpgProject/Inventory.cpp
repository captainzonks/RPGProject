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

void Inventory::GetWeaponL(std::unique_ptr<Weapon> weaponL)
{
	hasWeaponL = true;
	attackDiceL = weaponL->GetAttackDieWeapon();
	AddToInventory(std::move(weaponL));
}

void Inventory::GetWeaponR(std::unique_ptr<Weapon> weaponR)
{
	hasWeaponR = true;
	attackDiceR = weaponR->GetAttackDieWeapon();
	AddToInventory(std::move(weaponR));
}

void Inventory::AddToInventory(std::unique_ptr<Item> item)
{
	if (this->capacity > 0)
	{
		this->inventory.push_back(std::move(item));
		this->capacity--;
	}
	else
		std::cout << "You don't have enough room!" << std::endl;
}

void Inventory::AddPotionToInventory(std::unique_ptr<Potion> potion)
{
	if (this->potionCapacity > 0)
	{
		this->potionInventory.push_back(std::move(potion));
		this->potionCapacity--;
	}
	else
		std::cout << "You don't have enough room!" << std::endl;
}

void Inventory::RemoveFromInventory(std::unique_ptr<Item> item)
{
	std::vector<std::unique_ptr<Item>>::iterator itr{ std::find(inventory.begin(), inventory.end(), item) };
	this->inventory.erase(inventory.begin() + std::distance(inventory.begin(), itr));
	capacity++;
}

void Inventory::RemovePotionFromInventory(std::unique_ptr<Potion> potion)
{
	std::vector<std::unique_ptr<Potion>>::iterator itr{ std::find(potionInventory.begin(), potionInventory.end(), potion) };
	this->potionInventory.erase(potionInventory.begin() + std::distance(potionInventory.begin(), itr));
	potionCapacity++;
}

void Inventory::DisplayInventory() const
{
	cout << "=====INVENTORY=====" << endl;
	int counter{ 1 };
	if (this->inventory.size() == 0)
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		for (auto& i : this->inventory)
		{
			cout << counter << ": " << *i << endl;
			counter++;
		}
	}
	cout << "===================" << endl;
}

void Inventory::DisplayPotions() const
{
	cout << "\n=====POTION BAG=====" << endl;
	int counter{ 1 };
	if (this->potionInventory.size() == 0)
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		for (auto& i : this->potionInventory)
		{
			cout << counter << ": " << *i << " +" << i->GetHealthValue() << "HP" << endl;
			counter++;
		}
	}
	cout << "====================" << endl;
}

std::unique_ptr<Item> Inventory::GetItem(int itemNumber)
{
	return std::move(inventory.at(static_cast<size_t>(itemNumber - 1)));
}

std::unique_ptr<Potion> Inventory::GetPotion(int itemNumber)
{
	return std::move(potionInventory.at(static_cast<size_t>(itemNumber - 1)));
}

bool Inventory::HasWeapon()
{
	return hasWeaponL;
}

int Inventory::GetAttackDiceL()
{
	return attackDiceL;
}

int Inventory::GetAttackDiceR()
{
	return attackDiceR;
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
