#include "Currency.h"

Currency::Currency()
{
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

void Currency::displayMoney()
{
	cout << "============" << endl;
	cout << "Gold   : " << this->getGold() << endl;
	cout << "Silver : " << this->getSilver() << endl;
	cout << "Copper : " << this->getCopper() << endl;
	cout << "============" << endl;
}

void Currency::addMoney(int gold, int silver, int copper)
{
	this->gold += gold;
	this->silver += silver;
	this->copper += copper;
}

void Currency::subtractMoney(int gold, int silver, int copper)
{
	if (gold != 0 && this->gold >= gold)
		this->gold -= gold;
	else if (gold == 0)
	{
	}
	else
		cout << "You don't have enough gold!" << endl;
	if (silver != 0 && this->silver >= silver)
		this->silver -= silver;
	else if (silver == 0)
	{
	}
	else
		cout << "You don't have enough silver!" << endl;
	if (copper != 0 && this->copper >= copper)
		this->copper -= copper;
	else if (copper == 0)
	{
	}
	else
		cout << "You don't have enough copper!" << endl;
}