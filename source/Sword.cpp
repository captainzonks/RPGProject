#include "Sword.h"

Sword::Sword()
{
	this->name = "Sword";
	this->attackDie = 6;
	this->durability = 20;
	this->value = 1000;
	this->level = 1;
	this->damageType = DAMAGE_TYPE::SLASHING;
	this->weaponType = WEAPON_TYPE::MELEE;
	this->weaponProficiency = WEAPON_PROFICIENCY::MARTIAL;
}

Sword::Sword(std::string swordType)
{
	if (swordType == "Shortsword")
	{
		this->name = "Shortsword";
		this->durability = 20;
		this->value = 1000;
		this->level = 1;
		this->isFinesse = true;
		this->isTwoHanded = false;
		this->attackDie = 6;
		this->damageType = DAMAGE_TYPE::PIERCING;
		this->weaponType = WEAPON_TYPE::MELEE;
		this->weaponProficiency = WEAPON_PROFICIENCY::MARTIAL;
	}
	else if (swordType == "Greatsword")
	{
		this->name = "Greatsword";
		this->durability = 20;
		this->value = 5000;
		this->level = 1;
		this->isFinesse = false;
		this->isTwoHanded = true;
		this->attackDie = 6;
	}
}

Sword::~Sword()
{
}