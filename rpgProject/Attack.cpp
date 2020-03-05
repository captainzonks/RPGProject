#include "Attack.h"

bool Attack::AttackAgainstAC(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> target)
{
	bool success{ false };
	std::cout << "\n" << attacker->getName() << " is attacking " << target->getName() << "!" << std::endl;
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
	if (!target->livingOrDead())
	{
		std::cout << attacker->getName() << " killed " << target->getName() << "!" << std::endl;
		attacker->myCurrency.addMoney(target->myCurrency.getCopper());
		std::cout << attacker->getName() << " looted " << target->myCurrency.getCopper() << " copper!" << std::endl;
		int xpGain{ (rand() % 25 + 1) * target->getStrengthMod() };
		attacker->addXP(xpGain);
		std::cout << attacker->getName() << " gained " << xpGain << " XP!" << std::endl;
	}
}