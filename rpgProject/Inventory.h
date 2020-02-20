#pragma once

#include "Sword.h"

class Inventory
{
public:

	Inventory();

	void getASword();

	int getCapacity();

private:
	bool haveSword{ false };
	int capacity{ 10 };
};

