#include "Sword.h"

Sword::Sword()
{
	this->name = "Sword";
	this->attackDie = 6;
	this->durability = 20;
	this->value = 1000;
	this->level = 1;
	this->damage_type_ = damage_type::slashing;
	this->weaponType = weapon_type::melee;
	this->weaponProficiency = weapon_proficiency::martial;
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
		this->damage_type_ = damage_type::piercing;
		this->weaponType = weapon_type::melee;
		this->weaponProficiency = weapon_proficiency::martial;
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