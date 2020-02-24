#pragma once

#include "Weapon.h"

class Sword :
	public Weapon
{
public:
	// constructors
	Sword();
	Sword(string name, int attackDie);

	// destructor
	virtual ~Sword() override;

	// print override
	virtual void print(ostream& os) const override
	{
		os << getName();
	}

	// getters
	virtual string getName() const override;
	virtual int getAttackDie() const override;
	virtual int getDurability() const override;

private:
	string name;
	int attackDie;
	int durability;
};

