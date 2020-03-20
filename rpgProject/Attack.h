#ifndef ATTACK_H
#define ATTACK_H

#include "HelperFunctions.h"
#include "Actor.h"

class Actor;

class Attack
{
public:
	static bool AttackAgainstAC(Actor& attacker, Actor& target);
	static void DealDamage(Actor& attacker, Actor& target);
	static void DealCriticalDamage(Actor& attacker, Actor& target);

	static void DealDamageDualWielding(Actor& attacker, Actor& target, char hand);
	static void DealCriticalDamageDualWielding(Actor& attacker, Actor& target);

	static int CheckForAttackModifier(Actor& attacker);
	static int CheckForACModifier(Actor& target);
private:
	Attack();
};

#endif // !ATTACK_H