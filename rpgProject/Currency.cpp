#include "Currency.h"

Currency::Currency()
{
}

Currency::~Currency()
{
	std::cout << "Currency destructor called" << std::endl;
}

Currency::Currency(int copper)
{
	this->copper = copper;
}

int Currency::getGold()
{
	return copper / 100;
}

int Currency::getSilver()
{
	return copper / 10;
}

int Currency::getCopper()
{
	return copper;
}

void Currency::displayMoney()
{
	int tempCopper = copper;
	int gold = tempCopper / 100;
	tempCopper %= 100;
	int silver = tempCopper / 10;
	tempCopper %= 10;

	cout << "============" << endl;
	cout << "Gold   : " << gold << endl;
	cout << "Silver : " << silver << endl;
	cout << "Copper : " << tempCopper << endl;
	cout << "============" << endl;
}

void Currency::addMoney(int copper)
{
	this->copper += copper;
}

void Currency::subtractMoney(int copper)
{
	if (copper > this->copper)
	{
		std::cout << "You don't have enough copper!" << std::endl;
	}
	else
		this->copper -= copper;
}