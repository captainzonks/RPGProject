#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::endl;

class I_Display
{
	friend ostream& operator<<(ostream& os, const I_Display& obj);

public:
	virtual void Print(ostream& os) const = 0;
};

