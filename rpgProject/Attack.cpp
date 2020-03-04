#include "Attack.h"

bool Attack::AttackAgainstAC(int modifier, int AC)
{
	bool success{ false };

	int result{ rollDice(1, 20) + modifier };
	if (result < AC)
		return false;
	else
		return true;
}

void Attack::DealDamage(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> target)
{
	int total = rollDice(1, 4);
	target->subtractHealth(total);
	std::cout << "\n" << attacker->getName() << " did " << total << " damage to " << target->getName() << std::endl;
}