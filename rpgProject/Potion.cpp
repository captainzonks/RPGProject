#include "Potion.h"

Potion::Potion(int healthValue)
{
	this->healthValue = healthValue;
}

Potion::~Potion()
{
}

int Potion::GetHealthValue()
{
	return this->healthValue;
}

int Potion::UsePotion()
{
	return this->GetHealthValue();
}

void Potion::Destroy()
{
	delete this;
}
