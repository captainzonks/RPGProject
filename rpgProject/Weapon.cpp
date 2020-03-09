#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

int Weapon::GetAttackDie() const
{
	return attackDie;
}

int Weapon::GetModifier() const
{
	return attackModifier;
}

void Weapon::UpgradeWeapon()
{
	this->level++;
	this->attackModifier++;
	this->value += 150;
}
