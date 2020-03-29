#pragma once

#include "Weapon.h"

class Sword :
	public Weapon
{
public:
	// constructors
	Sword();
	Sword(std::string name, int attackDie, DAMAGE_TYPE damageType, int durability, int value, int level);

	// destructor
	virtual ~Sword() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:
};

