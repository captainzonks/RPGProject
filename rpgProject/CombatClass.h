#pragma once

#include "Constants.h"
#include <iostream>
#include <vector>

class CombatClass
{
public:

	virtual ~CombatClass() = 0;

	virtual int GetHitDice() = 0;
	virtual int GetHitDiceQuantity() = 0;

protected:
	int hitDice{};
	int hitDiceQuantity{};
};

