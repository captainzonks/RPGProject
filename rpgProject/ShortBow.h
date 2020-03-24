#pragma once
#include "Weapon.h"
class ShortBow :
	public Weapon
{
public:
	// constructors
	ShortBow();
	ShortBow(std::string name, int attackDie, DAMAGE_TYPE damageType, int durability, int value, int level);

	// destructor
	virtual ~ShortBow() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

private:

};

