#pragma once

#include "Item.h"

class Armor :
	public Item
{
public:

	// constructors
	Armor();
	
	// destructors
	virtual ~Armor() override;

	// getter
	virtual int GetArmorValue() const = 0;

private:
};

