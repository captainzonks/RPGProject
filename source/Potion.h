#pragma once
#include "Item.h"
class Potion :
	public Item
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
	ITEM_TYPE itemType{ ITEM_TYPE::POTION };
};

