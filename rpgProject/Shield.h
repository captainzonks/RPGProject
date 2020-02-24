#pragma once

#include "Armor.h"

class Shield :
	public Armor
{
public:

	// constructors
	Shield();
	Shield(string name, int armorValue);

	// destructor
	virtual ~Shield() override;

	// print override
	virtual void print(ostream& os) const override
	{
		os << getName();
	}

	// getters
	virtual string getName() const override;
	virtual int getArmorValue() const override;
	virtual int getDurability() const override;

private:
	string name;
	int durability;
	int armorValue;
};

