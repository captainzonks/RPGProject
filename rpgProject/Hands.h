#pragma once

#include "Armor.h"

class Hands :
	public Armor
{
public:

	// constructors
	Hands();
	Hands(string name, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Hands() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

