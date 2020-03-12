#pragma once

#include "Constants.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <limits>

class CombatClass
{
public:

	virtual ~CombatClass();

	virtual int GetHitDice() = 0;
	virtual int GetHitDiceQuantity() = 0;

protected:
	int hitDice{};
	int hitDiceQuantity{};
};

