#include "Currency.h"

Currency::Currency()
{
	gold = 10;
	silver = 5;
	copper = 1;
}

Currency::Currency(int gold, int silver, int copper)
{
	this->gold = gold;
	this->silver = silver;
	this->copper = copper;
}

int Currency::getGold()
{
	return gold;;
}

int Currency::getSilver()
{
	return silver;
}

int Currency::getCopper()
{
	return copper;
}
