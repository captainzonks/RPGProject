#pragma once

#include "Constants.h"
#include "Menu.h"
#include "Actor.h"
#include <iostream>
#include <vector>
#include <limits>

class CombatClass
	: public Actor
{
public:
	CombatClass();
	virtual ~CombatClass();

	virtual int GetHitDice();
	virtual int GetHitDiceQuantity();

protected:
	int hitDice{};
	int hitDiceQuantity{};
};

