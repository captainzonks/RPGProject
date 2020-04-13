#pragma once

#include "actor.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Sword.h"
#include "Shield.h"
#include "Helmet.h"
#include "Chest.h"
#include "Legs.h"
#include "Hands.h"
#include "Boots.h"

class Blacksmith
{
public:

	// constructor
	Blacksmith();

	// deconstructor
	~Blacksmith();

	// functions
	void MakeArmor(actor& actor);
	void MakeWeapon(actor& actor);

private:

};

