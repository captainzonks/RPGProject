#pragma once

#include "Armor.h"

class Shield :
	virtual public Armor
{
public:
	Shield();
	Shield(string name, int armorValue);

	virtual ~Shield() override;

	virtual string getName() override;
	int getArmorValue();

private:
	string name{};
	int armorValue{};
};

