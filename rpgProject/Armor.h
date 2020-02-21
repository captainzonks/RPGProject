#pragma once

#include "Item.h"

class Armor :
	virtual public Item
{
public:
	Armor();
	
	virtual ~Armor() override;

	virtual int getArmorValue();

private:
	int armorValue{};
};

