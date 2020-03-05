#pragma once

#include "Weapon.h"

class Sword :
	public Weapon
{
public:
	// constructors
	Sword();
	Sword(string name, int attackDie, int durability, int value);

	// destructor
	virtual ~Sword() override;

	// Print override
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}

	// getters
	virtual string GetName() const override;
	virtual int GetAttackDie() const override;
	virtual int GetDurability() const override;
	virtual int GetValue() const override;

private:
	int attackDie;
};

