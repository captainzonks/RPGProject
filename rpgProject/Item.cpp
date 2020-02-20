#include "Item.h"

Item::Item(string name)
{
	this->name = name;
}

string Item::getName()
{
	return name;
}

ostream& operator<<(ostream& os, const Item& item)
{
	os << item.name;
	return os;
}
