#pragma once
#include "Item.h"
class Potion :
	public Item
{
public:
	// constructor
	Potion(int healthValue);

	// destructor
	~Potion();
	
	// getter
	int GetHealthValue();

	// use
	int UsePotion();
	void Destroy();

private:
	int healthValue{};
};

