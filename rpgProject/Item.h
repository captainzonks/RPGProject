#pragma once

#include "I_Display.h"

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
	virtual string GetName() const = 0;
	virtual int GetValue() const = 0;
	virtual int GetDurability() const = 0;

protected:
	string name{};
	int durability{};
	int value{};
};

