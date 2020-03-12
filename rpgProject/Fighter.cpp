#include "Fighter.h"

Fighter::Fighter()
{
	this->hitDice = 10;
	this->hitDiceQuantity = 1;
}

Fighter::~Fighter()
{
	std::cout << "Fighter destructor called" << std::endl; // debug
}
