#pragma once
#include "Item.h"
class Potion :
	public item
{
public:
	// constructor
	Potion(int healthValue);

	// destructor
	virtual ~Potion() override;

	// print function
	virtual void Print(ostream& os) const override
	{
		os << GetName();
	}
	
	// getter
	int GetHealthValue();

	// use
	void Destroy();

private:
	int healthValue{};
	item_type itemType{ item_type::consumable };
};

