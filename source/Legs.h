#pragma once

#include "Armor.h"

class Legs :
	public Armor
{
public:

	// constructors
	Legs();
	Legs(std::string name, ARMOR_TYPE armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Legs() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:

};

