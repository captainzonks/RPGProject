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
	virtual int GetAttackDie() const;
	virtual int GetModifier() const;

	// upgrade
	virtual void UpgradeWeapon();

protected:
	int attackDie{};
	int attackModifier{};
	ITEM_TYPE itemType{ ITEM_TYPE::WEAPON };
};

