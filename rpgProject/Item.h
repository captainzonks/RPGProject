#pragma once

#include "I_Display.h"
#include "Constants.h"

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Item
	: public I_Display
{
public:

	// constructor
	Item();

	// destructor
	virtual ~Item();

	// Print override
	virtual void Print(ostream& os) const override = 0;

	// getter
	virtual string GetName() const
	{
		return this->name;
	}
	virtual int GetValue() const
	{
		return this->value;
	}
	virtual int GetDurability() const
	{
		return this->durability;
	}
	virtual int GetLevel() const
	{
		return this->level;
	}
	virtual DAMAGE_TYPE GetDamageType()
	{
		return this->type;
	}

protected:
	string name{};
	int durability{};
	int value{};
	int level{};
	DAMAGE_TYPE type{ DAMAGE_TYPE::NONE };
};

