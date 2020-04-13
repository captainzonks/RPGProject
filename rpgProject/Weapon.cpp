#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

int Weapon::GetAttackDieWeapon() const
{
	return attackDie;
}

int Weapon::GetModifier() const
{
	return attackModifier;
}

weapon_type Weapon::GetWeaponType() const
{
	return weaponType;
}

bool Weapon::IsFinesse()
{
	return isFinesse;
}

bool Weapon::IsTwoHanded()
{
	return isTwoHanded;
}

void Weapon::UpgradeWeapon()
{
	this->level++;
	this->attackModifier++;
	this->value += 150;
}
