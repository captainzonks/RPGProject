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

	// print override
	virtual void print(ostream& os) const override = 0;

	// getter
	virtual string getName() const = 0;
	virtual int getDurability() const = 0;

private:
};

