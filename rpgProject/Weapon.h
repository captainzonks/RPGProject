#pragma once

#include "Item.h"

class Weapon :
	public item
{
public:

	// constructor
	Weapon();

	// destructor
	virtual ~Weapon() override;

	// getter
	virtual int GetAttackDieWeapon() const;
	virtual int GetModifier() const;
	virtual weapon_type GetWeaponType() const;
	virtual bool IsFinesse(), IsTwoHanded();

	// upgrade
	virtual void UpgradeWeapon();

protected:
	int attackDie{};
	int attackModifier{};
	bool isFinesse{};
	bool isTwoHanded{};
	item_type itemType{ item_type::weapon };
	weapon_type weaponType{ weapon_type::none };
	weapon_proficiency weaponProficiency{ weapon_proficiency::none };
};

