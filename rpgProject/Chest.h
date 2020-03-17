#pragma once

#include "Armor.h"

class Chest :
	public Armor
{
public:

	// constructors
	Chest();
	Chest(string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Chest() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}
private:

};

