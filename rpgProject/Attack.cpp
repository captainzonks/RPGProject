#include "Attack.h"

bool Attack::AttackAgainstAC(Actor& attacker, Actor& target)
{
	bool success{ false };
	int result{};
	int result2{};
	std::cout << "\n" << attacker.GetName() << " is attacking " << target.GetName() << "!" << std::endl;

	if (attacker.myUpgrades.IsDualWielding())
	{
		result = RollDice(1, 20);
		result2 = RollDice(1,20);
		if (result >= 20 && result2 >= 20)
		{
			std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20 with the both hits! Double critical hit!" << std::endl;
			DealCriticalDamage(attacker, target);
			DealCriticalDamage(attacker, target);
			return true;
		}
		else if (result >= 20 || result2 >= 20)
		{
			std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20! Critical hit!" << std::endl;
			DealCriticalDamage(attacker, target);
			return true;
		}
	}

	result = RollDice(1, 20);

	// check for a critical hit (natural 20)
	if (result >= 20)
	{
		std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20! Critical hit!" << std::endl;
		DealCriticalDamage(attacker, target);
		return true;
	}

	// if not a crit, add on modifiers
	result += CheckForAttackModifier(attacker);
	if (attacker.myUpgrades.RangedWeaponEquipped())
		result += attacker.GetDexMod();
	else if (attacker.myUpgrades.weaponL->IsFinesse() || attacker.myUpgrades.weaponR->IsFinesse())
		result += attacker.GetDexMod();
	else
		result += attacker.GetStrengthMod();

	// handle regular hit or miss
	std::cout << "\n\t" << attacker.GetName() << " rolled a " << result << " vs " << (target.GetArmorClass() + CheckForACModifier(target)) << " AC" << std::endl;
	if (result < (target.GetArmorClass() + CheckForACModifier(target) + target.myInventory.GetArmorBonus()))
		return false;
	else
		DealDamage(attacker, target);
		return true;
}

void Attack::DealDamage(Actor& attacker, Actor& target)
{
	int total{};
	if (attacker.myUpgrades.WeaponLEquipped())
	{
		if (attacker.myUpgrades.weaponL->GetWeaponType() == WEAPON_TYPE::MELEE)
		{
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.GetStrengthMod();
		}
		else if (attacker.myUpgrades.weaponL->GetWeaponType() == WEAPON_TYPE::RANGED)
		{
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.GetDexMod();
		}

	}
	if (attacker.myUpgrades.WeaponREquipped())
	{
		if (attacker.myUpgrades.weaponR->GetWeaponType() == WEAPON_TYPE::MELEE)
		{
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.GetStrengthMod();
		}
		else if (attacker.myUpgrades.weaponR->GetWeaponType() == WEAPON_TYPE::RANGED)
		{
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.GetDexMod();
		}
	}

	if (attacker.GetFightingStyle() == FIGHTING_STYLE::DUELING)
	{
		total += 2;
	}

	if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
		&& static_cast<int>(target.GetResistance()) != 0)
	{
		total /= 2;
		std::cout << "\tDamage halved!" << std::endl;
	}
	if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
		&& static_cast<int>(target.GetVulnerability()) != 0)
	{
		total *= 2;
		std::cout << "\tDamage doubled!" << std::endl;
	}


	target.SubtractHealth(total);
	std::cout << "\t" << attacker.GetName() << " did " << total << " damage to " << target.GetName() << std::endl;
	if (!target.LivingOrDead())
	{
		std::cout << "\t" << attacker.GetName() << " killed " << target.GetName() << "!" << std::endl;
		
		// loot the moneys
		attacker.myCurrency.AddMoney(target.myCurrency.GetCopper());
		if (target.myCurrency.GetGold() >= 1)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() / 100 << " gold!" << std::endl;
		if (target.myCurrency.GetGold() == 0 && target.myCurrency.GetSilver() >= 1)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() / 10 << " silver!" << std::endl;
		if (target.myCurrency.GetGold() == 0 && target.myCurrency.GetSilver() == 0)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() << " copper!" << std::endl;

		// get the XP gains
		int xpGain{ (rand() % 25 + 1) * target.GetLevel() };
		attacker.AddXP(xpGain);
		std::cout << "\t" << attacker.GetName() << " gained " << xpGain << " XP!" << std::endl;
	}
}

void Attack::DealCriticalDamage(Actor& attacker, Actor& target)
{
	int total{};
	if (attacker.myUpgrades.WeaponLEquipped())
	{
		if (attacker.myUpgrades.weaponL->GetWeaponType() == WEAPON_TYPE::MELEE)
		{
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) * 2) + attacker.GetStrengthMod();
		}
		else if (attacker.myUpgrades.weaponL->GetWeaponType() == WEAPON_TYPE::RANGED)
		{
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) * 2) + attacker.GetDexMod();
		}
	}
	if (attacker.myUpgrades.WeaponREquipped())
	{
		if (attacker.myUpgrades.weaponR->GetWeaponType() == WEAPON_TYPE::MELEE)
		{
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) * 2) + attacker.GetStrengthMod();
		}
		else if (attacker.myUpgrades.weaponR->GetWeaponType() == WEAPON_TYPE::RANGED)
		{
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) * 2) + attacker.GetDexMod();
		}
	}

	if (attacker.GetFightingStyle() == FIGHTING_STYLE::DUELING)
	{
		total += 2;
	}

	if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
		&& static_cast<int>(target.GetResistance()) != 0)
	{
		total /= 2;
		std::cout << "\tDamage halved!" << std::endl;
	}
	if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
		&& static_cast<int>(target.GetVulnerability()) != 0)
	{
		total *= 2;
		std::cout << "\tDamage doubled!" << std::endl;
	}


	target.SubtractHealth(total);
	std::cout << "\t" << attacker.GetName() << " did " << total << " damage to " << target.GetName() << std::endl;
	if (!target.LivingOrDead())
	{
		std::cout << "\t" << attacker.GetName() << " killed " << target.GetName() << "!" << std::endl;

		// loot the moneys
		attacker.myCurrency.AddMoney(target.myCurrency.GetCopper());
		if (target.myCurrency.GetGold() >= 1)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() / 100 << " gold!" << std::endl;
		if (target.myCurrency.GetGold() == 0 && target.myCurrency.GetSilver() >= 1)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() / 10 << " silver!" << std::endl;
		if (target.myCurrency.GetGold() == 0 && target.myCurrency.GetSilver() == 0)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() << " copper!" << std::endl;

		// get the XP gains
		int xpGain{ (rand() % 25 + 1) * target.GetLevel() };
		attacker.AddXP(xpGain);
		std::cout << "\t" << attacker.GetName() << " gained " << xpGain << " XP!" << std::endl;
	}
}

void Attack::DealDamageDualWielding(Actor& attacker, Actor& target, char hand)
{
	int total{};
	if (hand == 'L')
	{
		total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.GetStrengthMod();
	}
	else if (hand == 'R')
	{
		total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.GetStrengthMod();
	}

	if (attacker.GetFightingStyle() == FIGHTING_STYLE::DUELING)
	{
		total += 2;
	}

	if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
		&& static_cast<int>(target.GetResistance()) != 0)
	{
		total /= 2;
		std::cout << "\tDamage halved!" << std::endl;
	}
	if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
		&& static_cast<int>(target.GetVulnerability()) != 0)
	{
		total *= 2;
		std::cout << "\tDamage doubled!" << std::endl;
	}


	target.SubtractHealth(total);
	std::cout << "\t" << attacker.GetName() << " did " << total << " damage to " << target.GetName() << std::endl;
	if (!target.LivingOrDead())
	{
		std::cout << "\t" << attacker.GetName() << " killed " << target.GetName() << "!" << std::endl;

		// loot the moneys
		attacker.myCurrency.AddMoney(target.myCurrency.GetCopper());
		if (target.myCurrency.GetGold() >= 1)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() / 100 << " gold!" << std::endl;
		if (target.myCurrency.GetGold() == 0 && target.myCurrency.GetSilver() >= 1)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() / 10 << " silver!" << std::endl;
		if (target.myCurrency.GetGold() == 0 && target.myCurrency.GetSilver() == 0)
			std::cout << "\t" << attacker.GetName() << " looted " << target.myCurrency.GetCopper() << " copper!" << std::endl;

		// get the XP gains
		int xpGain{ (rand() % 25 + 1) * target.GetLevel() };
		attacker.AddXP(xpGain);
		std::cout << "\t" << attacker.GetName() << " gained " << xpGain << " XP!" << std::endl;
	}
}

void Attack::DealCriticalDamageDualWielding(Actor& attacker, Actor& target)
{
}

int Attack::CheckForAttackModifier(Actor& attacker)
{
	int modifier{};

	if (attacker.GetCombatClass() == COMBAT_CLASS::FIGHTER)
	{
		if (attacker.GetFightingStyle() == FIGHTING_STYLE::ARCHERY)
		{
			if (attacker.myUpgrades.rangedWeapon->GetWeaponType() == WEAPON_TYPE::RANGED)
			{
				modifier = 2;
			}
		}
	}

	return modifier;
}

int Attack::CheckForACModifier(Actor& target)
{
	int modifier{};

	if (target.GetCombatClass() == COMBAT_CLASS::FIGHTER)
	{
		if (target.GetFightingStyle() == FIGHTING_STYLE::DEFENSE)
		{
			if (target.myUpgrades.ChestEquipped() ||
				target.myUpgrades.HelmetEquipped() ||
				target.myUpgrades.LegsEquipped() ||
				target.myUpgrades.HandsEquipped() ||
				target.myUpgrades.BootsEquipped() ||
				target.myUpgrades.ShieldEquipped())
			{
				modifier = 1;
			}
		}
	}

	return modifier;
}
