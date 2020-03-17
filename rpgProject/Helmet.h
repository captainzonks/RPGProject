#pragma once
#include "Armor.h"
class Helmet :
	public Armor
{
public:

	// constructors
	Helmet();
	Helmet(string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Helmet() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

