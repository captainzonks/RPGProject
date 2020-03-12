#include "Attack.h"

bool Attack::AttackAgainstAC(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> target)
{
	bool success{ false };
	std::cout << "\n" << attacker->GetName() << " is attacking " << target->GetName() << "!" << std::endl;
	int result{ RollDice(1, 20) + attacker->GetStrengthMod() };
	std::cout << "\n" << attacker->GetName() << " rolled a " << result << " vs " << target->GetArmorClass() << " AC" << std::endl;
	if (result < (target->GetArmorClass() + target->myInventory.GetArmorBonus()))
		return false;
	else
		return true;
}

void Attack::DealDamage(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> target)
{
	int total = RollDice(1, attacker->myUpgrades.GetAttackDie());

	if (attacker->myUpgrades.WeaponEquipped())
		total += attacker->myUpgrades.weapon->GetModifier();

	total += attacker->GetStrengthMod();

	if (static_cast<int>(target->GetResistance()) == static_cast<int>(attacker->myUpgrades.GetAttackDamageType())
		&& static_cast<int>(target->GetResistance()) != 0)
	{
		total /= 2;
		std::cout << "Damage halved!" << std::endl;
	}
	if (static_cast<int>(target->GetVulnerability()) == static_cast<int>(attacker->myUpgrades.GetAttackDamageType())
		&& static_cast<int>(target->GetVulnerability()) != 0)
	{
		total *= 2;
		std::cout << "Damage doubled!" << std::endl;
	}


	target->SubtractHealth(total);
	std::cout << "\n" << attacker->GetName() << " did " << total << " damage to " << target->GetName() << std::endl;
	if (!target->LivingOrDead())
	{
		std::cout << attacker->GetName() << " killed " << target->GetName() << "!" << std::endl;
		
		// loot the moneys
		attacker->myCurrency.AddMoney(target->myCurrency.GetCopper());
		if (target->myCurrency.GetGold() >= 1)
			std::cout << attacker->GetName() << " looted " << target->myCurrency.GetCopper() / 100 << " gold!" << std::endl;
		if (target->myCurrency.GetGold() == 0 && target->myCurrency.GetSilver() >= 1)
			std::cout << attacker->GetName() << " looted " << target->myCurrency.GetCopper() / 10 << " silver!" << std::endl;
		if (target->myCurrency.GetGold() == 0 && target->myCurrency.GetSilver() == 0)
			std::cout << attacker->GetName() << " looted " << target->myCurrency.GetCopper() << " copper!" << std::endl;

		// get the XP gains
		int xpGain{ (rand() % 25 + 1) * target->GetLevel() };
		attacker->AddXP(xpGain);
		std::cout << attacker->GetName() << " gained " << xpGain << " XP!" << std::endl;
	}
}