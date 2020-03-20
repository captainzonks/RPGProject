#ifndef ATTACK_H
#define ATTACK_H

#include "HelperFunctions.h"
#include "Actor.h"

class Actor;

class Attack
{
public:
	// the primary attack function
	static bool MakeAnAttack(Actor& attacker, Actor& target);

	// the damage functions
	static void DealDamage(Actor& attacker, Actor& target, char hand, bool finesse);
	static void DealCriticalDamage(Actor& attacker, Actor& target, char hand, bool finesse);

	static void DealDamageDualWielding(Actor& attacker, Actor& target, char hand);
	static void DealCriticalDamageDualWielding(Actor& attacker, Actor& target);

	static int CheckForAttackModifier(Actor& attacker);
	static int CheckForACModifier(Actor& target);

	// death check
	static bool TargetKilled(Actor& attacker, Actor& target);

	// loot function
	static void LootCorpse(Actor& attacker, Actor& target);

private:
	Attack();
};

#endif // !ATTACK_H