#pragma once

#include "Armor.h"

class Boots :
	public Armor
{
public:

	// constructors
	Boots();
	Boots(string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Boots() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

