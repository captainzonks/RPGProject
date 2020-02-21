#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Item
{
public:
	Item();
	Item(string name);

	virtual ~Item();

	// overload ostream to display item (just its name for now)
	friend ostream& operator<<(ostream& os, const Item& item);

	virtual string getName();

private:
	string name{ "You Should Never See This Name" };
};

