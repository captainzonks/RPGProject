#pragma once

#include "Armor.h"

class Hands :
	public Armor
{
public:

	// constructors
	Hands();
	Hands(std::string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Hands() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

