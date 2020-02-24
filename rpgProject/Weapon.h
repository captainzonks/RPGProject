#pragma once

#include "Item.h"

class Weapon :
	public Item
{
public:

	// constructor
	Weapon();

	// destructor
	virtual ~Weapon() override;

	// getter
	virtual int getAttackDie() const = 0;

private:
};

