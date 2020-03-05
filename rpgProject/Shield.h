#pragma once

#include "Armor.h"

class Shield :
	public Armor
{
public:

	// constructors
	Shield();
	Shield(string name, int armorValue, int durability, int value);

	// destructor
	virtual ~Shield() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

	// getters
	virtual string GetName() const override;
	virtual int GetArmorValue() const override;
	virtual int GetDurability() const override;
	virtual int GetValue() const override;

private:
	int armorValue;
};

