#pragma once
#include "Armor.h"
class Helmet :
	public Armor
{
public:

	// constructors
	Helmet();
	Helmet(std::string name, armor_type armorType, int armorValue, int durability, int value, int level);

	// destructor
	virtual ~Helmet() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

