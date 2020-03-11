#include "Potion.h"

Potion::Potion(int healthValue)
{
	this->name = "Healing Potion";
	this->healthValue = healthValue;
	this->value = 50;
}

Potion::~Potion()
{
}

int Potion::GetHealthValue()
{
	return this->healthValue;
}

void Potion::Destroy()
{
	delete this;
}
