#pragma once

#include "Item.h"

class Armor :
	public Item
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
	ITEM_TYPE itemType{ ITEM_TYPE::ARMOR };
	ARMOR_TYPE armorType{ ARMOR_TYPE::NONE };
};

