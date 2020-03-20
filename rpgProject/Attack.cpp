#include "Attack.h"

bool Attack::MakeAnAttack(Actor& attacker, Actor& target)
{
	bool success{ false };

	std::cout << "\n" << attacker.GetName() << " is attacking " << target.GetName() << "!" << std::endl;

	// check if dual wielding
	if (attacker.myUpgrades.IsDualWielding())
	{
		int resultL{ RollDice(1, 20) };
		int resultR{ RollDice(1, 20) };
		bool weaponLfinesse{ attacker.myUpgrades.weaponL->IsFinesse() };
		bool weaponRfinesse{ attacker.myUpgrades.weaponR->IsFinesse() };
		// check for double critical hits
		if (resultL == 20 && resultR == 20)
		{
			std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20 with the both hits! Double critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, 'L', weaponLfinesse);
			if (!TargetKilled(attacker, target))
			{
				DealCriticalDamage(attacker, target, 'R', weaponRfinesse);
				if (TargetKilled(attacker, target))
					LootCorpse(attacker, target);
			}
			else
			{
				LootCorpse(attacker, target);
			}
			success = true;
		}
		// check left hand for critical hit
		else if (resultL == 20 && resultR != 20)
		{
			std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20 with the first attack! Critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, 'L', weaponLfinesse);
			if (!TargetKilled(attacker, target))
			{
				DealDamage(attacker, target, 'R', weaponRfinesse);
				if (TargetKilled(attacker, target))
					LootCorpse(attacker, target);
			}
			else
			{
				LootCorpse(attacker, target);
			}
			success = true;
		}
		// check right hand for critical hit
		else if (resultR == 20 && resultL != 20)
		{
			std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20 with the second attack! Critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, 'R', weaponRfinesse);
			if (!TargetKilled(attacker, target))
			{
				DealDamage(attacker, target, 'L', weaponLfinesse);
				if (TargetKilled(attacker, target))
					LootCorpse(attacker, target);
			}
			else
			{
				LootCorpse(attacker, target);
			}
			success = true;
		}
		else
		{
			// check weapons for finesse, if so, add Dex, if not, add Strength
			if (weaponLfinesse)
				resultL += attacker.GetDexMod();
			if (weaponRfinesse)
				resultR += attacker.GetDexMod();
			if (!weaponLfinesse && !weaponRfinesse)
			{
				resultL += attacker.GetStrengthMod();
				resultR += attacker.GetStrengthMod();
			}
			std::cout << "\n\t" << "1st attack: " << attacker.GetName() << " rolled a " << resultL
				<< " vs " << (target.GetArmorClass() + CheckForACModifier(target)) << " AC" << std::endl;
			std::cout << "\n\t" << "2nd attack: " << attacker.GetName() << " rolled a " << resultR
				<< " vs " << (target.GetArmorClass() + CheckForACModifier(target)) << " AC" << std::endl;

			// check results and deal damage
			if (resultL < (target.GetArmorClass() + CheckForACModifier(target) + target.myInventory.GetArmorBonus()))
				success = false;
			else
			{
				DealDamage(attacker, target, 'L', weaponLfinesse);
				if (TargetKilled(attacker, target))
					LootCorpse(attacker, target);
				success = true;
			}

			if (resultR < (target.GetArmorClass() + CheckForACModifier(target) + target.myInventory.GetArmorBonus()) && !TargetKilled(attacker, target))
				success = false;
			else
			{
				DealDamage(attacker, target, 'R', weaponRfinesse);
				if (TargetKilled(attacker, target))
					LootCorpse(attacker, target);
				success = true;
			}
		}
		return success;
	}

	// if not dual wielding, then do a single weapon attack
	else
	{
		int result{ RollDice(1, 20) };
		char weaponHand{};
		bool weaponHandFinesse{};
		if (attacker.myUpgrades.WeaponLEquipped())
		{
			weaponHand = 'L';
			if (attacker.myUpgrades.weaponL->IsFinesse())
				weaponHandFinesse = true;
		}
		if (attacker.myUpgrades.WeaponREquipped())
		{
			weaponHand = 'R';
			if (attacker.myUpgrades.weaponR->IsFinesse())
				weaponHandFinesse = true;
		}

		// check for a critical hit (natural 20)
		if (result == 20)
		{
			std::cout << "\n\t" << attacker.GetName() << " rolled a natural 20! Critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, weaponHand, weaponHandFinesse);
			if (TargetKilled(attacker, target))
				LootCorpse(attacker, target);
			success = true;
		}

		// if not a crit, add on modifiers
		result += CheckForAttackModifier(attacker);
		if (attacker.myUpgrades.RangedWeaponEquipped())
			result += attacker.GetDexMod();
		else if (weaponHandFinesse)
			result += attacker.GetDexMod();
		else
			result += attacker.GetStrengthMod();

		// handle regular hit or miss
		std::cout << "\n\t" << attacker.GetName() << " rolled a " << result << " vs " << (target.GetArmorClass() + CheckForACModifier(target)) << " AC" << std::endl;
		if (result < (target.GetArmorClass() + CheckForACModifier(target) + target.myInventory.GetArmorBonus()))
			success = false;
		else
		{
			DealDamage(attacker, target, weaponHand, weaponHandFinesse);
			if (TargetKilled(attacker, target))
				LootCorpse(attacker, target);
			success = true;
		}
		return success;
	}
}

void Attack::DealDamage(Actor& attacker, Actor& target, char hand, bool finesse)
{
	int total{};
	// left hand
	if (hand == 'L')
	{
		// check for finesse
		if(!finesse)
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.GetStrengthMod();
		else if(finesse)
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.GetDexMod();

		// check for resistance
		if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
			&& static_cast<int>(target.GetResistance()) != 0)
		{
			total /= 2;
			std::cout << "\tDamage halved!" << std::endl;
		}
		// check for vulnerability
		if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
			&& static_cast<int>(target.GetVulnerability()) != 0)
		{
			total *= 2;
			std::cout << "\tDamage doubled!" << std::endl;
		}
	}
	// right hand
	else if (hand == 'R')
	{
		if (!finesse)
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.GetStrengthMod();
		else if (finesse)
			total += RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.GetDexMod();

		// check for resistance
		if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
			&& static_cast<int>(target.GetResistance()) != 0)
		{
			total /= 2;
			std::cout << "\tDamage halved!" << std::endl;
		}
		// check for vulnerability
		if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
			&& static_cast<int>(target.GetVulnerability()) != 0)
		{
			total *= 2;
			std::cout << "\tDamage doubled!" << std::endl;
		}
	}

	if (attacker.GetFightingStyle() == FIGHTING_STYLE::DUELING)
	{
		total += 2;
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

void Attack::DealCriticalDamage(Actor& attacker, Actor& target, char hand, bool finesse)
{
	int total{};
	// left hand
	if (hand == 'L')
	{
		// check for finesse
		if (!finesse)
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) * 2) + attacker.GetStrengthMod();
		else if (finesse)
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponL()) * 2) + attacker.GetDexMod();

		// check for resistance
		if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
			&& static_cast<int>(target.GetResistance()) != 0)
		{
			total /= 2;
			std::cout << "\tDamage halved!" << std::endl;
		}
		// check for vulnerability
		if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
			&& static_cast<int>(target.GetVulnerability()) != 0)
		{
			total *= 2;
			std::cout << "\tDamage doubled!" << std::endl;
		}
	}
	// right hand
	else if (hand == 'R')
	{
		if (!finesse)
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) * 2) + attacker.GetStrengthMod();
		else if (finesse)
			total += (RollDice(1, attacker.myUpgrades.GetAttackDieWeaponR()) * 2) + attacker.GetDexMod();

		// check for resistance
		if (static_cast<int>(target.GetResistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
			&& static_cast<int>(target.GetResistance()) != 0)
		{
			total /= 2;
			std::cout << "\tDamage halved!" << std::endl;
		}
		// check for vulnerability
		if (static_cast<int>(target.GetVulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
			&& static_cast<int>(target.GetVulnerability()) != 0)
		{
			total *= 2;
			std::cout << "\tDamage doubled!" << std::endl;
		}
	}

	if (attacker.GetFightingStyle() == FIGHTING_STYLE::DUELING)
	{
		total += 2;
	}

	target.SubtractHealth(total);
	std::cout << "\t" << attacker.GetName() << " did " << total << " damage to " << target.GetName() << std::endl;
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

void Attack::LootCorpse(Actor& attacker, Actor& target)
{
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

bool Attack::TargetKilled(Actor& attacker, Actor& target)
{
	bool dead{ false };
	if (!target.LivingOrDead())
	{
		std::cout << "\t" << attacker.GetName() << " killed " << target.GetName() << "!" << std::endl;
		dead = true;
	}
	return dead;
}
