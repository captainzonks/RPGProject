#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Item
{
public:

	Item(string name);

	// overload ostream to display item (just its name for now)
	friend ostream& operator<<(ostream& os, const Item& item);

	string getName();

private:
	string name{};
};

