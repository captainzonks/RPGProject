#include "Encounter.h"

Encounter::Encounter(EnemyManager& manager, Actor* player)
	: manager(manager), player(player)
{
}

void Encounter::encounterHandler(Actor* attacker, Actor* defender)
{
	// this is temporary code
	if (Attack::AttackAgainstAC(attacker->getStrength(), defender->getArmorClass()))
	{
		Attack::DealDamage(defender);
	}
	else
		std::cout << "Attack missed!" << std::endl;
}
