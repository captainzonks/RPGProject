#pragma once

#include "Item.h"

class Weapon :
	public Item
{
public:

	// constructor
	Weapon();

	// destructor
	virtual ~Weapon() override;

	// getter
	virtual int GetAttackDieWeapon() const;
	virtual int GetModifier() const;
	virtual WEAPON_TYPE GetWeaponType() const;
	virtual bool IsFinesse();

	// upgrade
	virtual void UpgradeWeapon();

protected:
	int attackDie{};
	int attackModifier{};
	bool isFinesse{};
	ITEM_TYPE itemType{ ITEM_TYPE::WEAPON };
	WEAPON_TYPE weaponType{ WEAPON_TYPE::NONE };
	WEAPON_PROFICIENCY weaponProficiency{ WEAPON_PROFICIENCY::NONE };
};

