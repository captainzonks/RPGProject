#include "Attack.h"

bool Attack::AttackAgainstAC(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> target)
{
	bool success{ false };

	int result{ rollDice(1, 20) + attacker->getStrengthMod() };
	if (result < (target->getArmorClass() + target->myInventory.GetArmorBonus()))
		return false;
	else
		return true;
}

void Attack::DealDamage(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> target)
{
	int total = rollDice(1, attacker->myInventory.GetAttackDice());
	target->subtractHealth(total);
	std::cout << "\n" << attacker->getName() << " did " << total << " damage to " << target->getName() << std::endl;
}