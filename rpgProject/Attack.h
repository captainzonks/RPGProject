#ifndef ATTACK_H
#define ATTACK_H

#include "HelperFunctions.h"
#include "Actor.h"

class Actor;

class Attack
{
public:
	static bool AttackAgainstAC(int modifier, int AC);
	static void DealDamage(Actor* target);
private:
	Attack();
};

#endif // !ATTACK_H