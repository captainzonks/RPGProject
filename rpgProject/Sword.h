#pragma once

#include "Item.h"

class Sword :
	virtual public Item
{
public:
	Sword();
	Sword(string name);

	virtual ~Sword() override;

	virtual string getName() override;
	int getAttackDie();
	int getDurability();

private:
	string name{};
	int attackDie{ 6 };
	int durability{ 20 };
};

