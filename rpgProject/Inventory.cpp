#include "Inventory.h"

Inventory::Inventory()
{
}

void Inventory::getASword()
{
	Sword mySword;
	haveSword = true;
}

int Inventory::getCapacity()
{
	return capacity;
}
