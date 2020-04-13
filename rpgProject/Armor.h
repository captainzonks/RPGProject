#pragma once

#include "Item.h"

class Armor :
	public item
{
public:

	// constructors
	Armor();
	
	// destructors
	virtual ~Armor() override;

	// getter
	virtual int GetArmorValue() const;

	// upgrade
	virtual void UpgradeArmor();

protected:
	int armorValue{};
	bool stealthDisadvantage{ false };
	item_type itemType{ item_type::armor };
	armor_type armorType{ armor_type::none };
};

