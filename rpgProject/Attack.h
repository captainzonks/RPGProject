#ifndef ATTACK_H
#define ATTACK_H

#include "HelperFunctions.h"
#include "actor.h"

class actor;

class Attack
{
public:
	// the primary attack function
	static void MakeAnAttack(actor& attacker, actor& target);

	// the damage functions
	static void DealDamage(actor& attacker, actor& target, char hand, bool finesse);
	static void DealCriticalDamage(actor& attacker, actor& target, char hand, bool finesse);

	// attack helper functions
	static int CheckForAttackModifier(actor& attacker);
	static int CheckForACModifier(actor& target);

	// loot function
	static void LootCorpse(actor& attacker, actor& target);

private:
	Attack();
};

#endif // !ATTACK_H