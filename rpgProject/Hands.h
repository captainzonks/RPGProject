#pragma once

#include "Armor.h"

class Hands :
	public Armor
{
public:

	// constructors
	Hands();
	Hands(std::string name, armor_type armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Hands() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

