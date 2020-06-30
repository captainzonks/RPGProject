#include "CombatClass.h"

CombatClass::CombatClass()
{
	std::cout << "CombatClass constructor called" << std::endl;
}

CombatClass::~CombatClass()
{
	std::cout << "CombatClass destructor called" << std::endl;
}

int CombatClass::GetHitDice()
{
	return hitDice;
}

int CombatClass::GetHitDiceQuantity()
{
	return hitDiceQuantity;
}
