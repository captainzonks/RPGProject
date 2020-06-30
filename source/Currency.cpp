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

int Currency::GetGold()
{
	return copper / 100;
}

int Currency::GetSilver()
{
	return copper / 10;
}

int Currency::GetCopper()
{
	return copper;
}

void Currency::DisplayMoney()
{
	int tempCopper = copper;
	int gold = tempCopper / 100;
	tempCopper %= 100;
	int silver = tempCopper / 10;
	tempCopper %= 10;

	cout << "\n====MONEY====" << endl;
	cout << "Gold   : " << gold << endl;
	cout << "Silver : " << silver << endl;
	cout << "Copper : " << tempCopper << endl;
	cout << "=============" << endl;
}

void Currency::AddMoney(int copper)
{
	this->copper += copper;
}

void Currency::SubtractMoney(int copper)
{
	if (copper > this->copper)
	{
		std::cout << "You don't have enough money!" << std::endl;
	}
	else
		this->copper -= copper;
}