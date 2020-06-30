#include "Armor.h"

Armor::Armor()
{
}

Armor::~Armor()
{
}

int Armor::GetArmorValue() const
{
	return this->armorValue;
}

void Armor::UpgradeArmor()
{
	this->level++;
	this->armorValue++;
	this->value += 150;
}
