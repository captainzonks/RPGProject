#pragma once

#include "Armor.h"

class Shield :
	public Armor
{
public:

	// constructors
	Shield();
	Shield(std::string name, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Shield() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

