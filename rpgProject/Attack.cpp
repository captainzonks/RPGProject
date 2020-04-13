#include "Attack.h"

void Attack::MakeAnAttack(actor& attacker, actor& target)
{

	std::cout << "\n" << attacker.get_name() << " is attacking " << target.get_name() << "!" << std::endl;

	// check if dual wielding
	if (attacker.is_dual_wielding())
	{
		int resultL{ roll_dice(1, 20) };
		int resultR{ roll_dice(1, 20) };
		bool weaponLfinesse{ attacker.myUpgrades.weaponL->IsFinesse() };
		bool weaponRfinesse{ attacker.myUpgrades.weaponR->IsFinesse() };
		// check for double critical hits
		if (resultL == 20 && resultR == 20)
		{
			std::cout << "\n\t" << attacker.get_name() << " rolled a natural 20 with the both hits! Double critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, 'L', weaponLfinesse);
			if (target.is_alive())
			{
				DealCriticalDamage(attacker, target, 'R', weaponRfinesse);
				if (!target.is_alive())
					LootCorpse(attacker, target);
				return;
			}
			else
			{
				LootCorpse(attacker, target);
				return;
			}
		}
		// check left hand for critical hit
		else if (resultL == 20 && resultR != 20)
		{
			std::cout << "\n\t" << attacker.get_name() << " rolled a natural 20 with the first attack! Critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, 'L', weaponLfinesse);
			if (target.is_alive())
			{
				// check for hit with R attack
				if (resultR < (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
				{
					std::cout << "\tSecond attack missed!" << std::endl;
					return;
				}

				else if (resultR >= (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
				{
					DealDamage(attacker, target, 'R', weaponRfinesse);
					if (!target.is_alive())
						LootCorpse(attacker, target);
					return;
				}
			}
			else
			{
				LootCorpse(attacker, target);
				return;
			}
		}
		// check right hand for critical hit
		else if (resultR == 20 && resultL != 20 && resultL > 0)
		{
			// handle first L attack
			if (resultL < (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
			{
				std::cout << "\tFirst attack missed!" << std::endl;
			}

			else if (resultL >= (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
			{
				DealDamage(attacker, target, 'L', weaponLfinesse);
				if (!target.is_alive())
				{
					LootCorpse(attacker, target);
					return;
				}
			}

			// check for living or dead then handle the R critical attack
			if (target.is_alive())
			{
				std::cout << "\n\t" << attacker.get_name() << " rolled a natural 20 with the second attack! Critical hit!" << std::endl;
				DealCriticalDamage(attacker, target, 'R', weaponRfinesse);
				if (!target.is_alive())
					LootCorpse(attacker, target);
				return;
			}
			else
			{
				LootCorpse(attacker, target);
				return;
			}
		}
		else
		{
			// check weapons for finesse, if so, add Dex, if not, add Strength
			if (weaponLfinesse)
				resultL += attacker.get_dex_mod();
			if (weaponRfinesse)
				resultR += attacker.get_dex_mod();
			if (!weaponLfinesse && !weaponRfinesse)
			{
				resultL += attacker.get_strength_mod();
				resultR += attacker.get_strength_mod();
			}
			// first attack
			std::cout << "\n\t" << "1st attack: " << attacker.get_name() << " rolled a " << resultL
				<< " vs " << (target.get_armor_class() + CheckForACModifier(target)) << " AC" << std::endl;
			// check results and deal damage
			if (resultL < (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
			{
				std::cout << "\tFirst attack missed!" << std::endl;
			}
			else if (resultL >= (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
			{
				DealDamage(attacker, target, 'L', weaponLfinesse);
				if (!target.is_alive())
				{
					LootCorpse(attacker, target);
					return;
				}

			}

			// second attack (check for death from first attack)
			if (target.is_alive())
			{
				std::cout << "\n\t" << "2nd attack: " << attacker.get_name() << " rolled a " << resultR
					<< " vs " << (target.get_armor_class() + CheckForACModifier(target)) << " AC" << std::endl;
				// check results and deal damage
				if (resultR < (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
				{
					std::cout << "\tSecond attack missed!" << std::endl;
					return;
				}

				else if (resultR >= (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
				{
					DealDamage(attacker, target, 'R', weaponRfinesse);
					if (!target.is_alive())
						LootCorpse(attacker, target);
					return;
				}
			}
		}
	}

	// if not dual wielding, then do a single weapon attack
	else
	{
		int result{ roll_dice(1, 20) };
		char weaponHand{};
		bool weaponHandFinesse{ false };
		if (attacker.myUpgrades.WeaponLEquipped())
		{
			weaponHand = 'L';
			if (attacker.myUpgrades.weaponL->IsFinesse())
				weaponHandFinesse = true;
		}
		else if (attacker.myUpgrades.WeaponREquipped())
		{
			weaponHand = 'R';
			if (attacker.myUpgrades.weaponR->IsFinesse())
				weaponHandFinesse = true;
		}
		else
		{
			weaponHand = 'R';
		}

		// check for a critical hit (natural 20)
		if (result == 20)
		{
			std::cout << "\n\t" << attacker.get_name() << " rolled a natural 20! Critical hit!" << std::endl;
			DealCriticalDamage(attacker, target, weaponHand, weaponHandFinesse);
			if (!target.is_alive())
				LootCorpse(attacker, target);
			return;
		}

		// if not a crit, add on modifiers
		result += CheckForAttackModifier(attacker);
		if (attacker.myUpgrades.RangedWeaponEquipped())
			result += attacker.get_dex_mod();
		else if (weaponHandFinesse)
			result += attacker.get_dex_mod();
		else
			result += attacker.get_strength_mod();

		// handle regular hit or miss
		std::cout << "\n\t" << attacker.get_name() << " rolled a " << result << " vs " << (target.get_armor_class() + CheckForACModifier(target)) << " AC" << std::endl;
		if (result < (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
		{
			std::cout << "\t" << attacker.get_name() << " missed!" << std::endl;
		}

		else if (result >= (target.get_armor_class() + CheckForACModifier(target) + target.myInventory.get_armor_bonus()))
		{
			DealDamage(attacker, target, weaponHand, weaponHandFinesse);
			if (!target.is_alive())
				LootCorpse(attacker, target);
		}
	}
}

void Attack::DealDamage(actor& attacker, actor& target, char hand, bool finesse)
{
	unsigned int total{};
	if (target.is_alive())
	{
		// left hand
		if (hand == 'L')
		{
			// check for finesse
			if (!finesse)
				total += roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.get_strength_mod();
			else if (finesse)
				total += roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponL()) + attacker.get_dex_mod();

			// check for resistance
			if (static_cast<int>(target.get_resistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
				&& static_cast<int>(target.get_resistance()) != 0)
			{
				total /= 2;
				std::cout << "\tDamage halved!" << std::endl;
			}
			// check for vulnerability
			if (static_cast<int>(target.get_vulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
				&& static_cast<int>(target.get_vulnerability()) != 0)
			{
				total *= 2;
				std::cout << "\tDamage doubled!" << std::endl;
			}
		}
		// right hand
		else if (hand == 'R')
		{
			if (!finesse)
				total += roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.get_strength_mod();
			else if (finesse)
				total += roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponR()) + attacker.get_dex_mod();

			// check for resistance
			if (static_cast<int>(target.get_resistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
				&& static_cast<int>(target.get_resistance()) != 0)
			{
				total /= 2;
				std::cout << "\tDamage halved!" << std::endl;
			}
			// check for vulnerability
			if (static_cast<int>(target.get_vulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
				&& static_cast<int>(target.get_vulnerability()) != 0)
			{
				total *= 2;
				std::cout << "\tDamage doubled!" << std::endl;
			}
		}

		if (attacker.GetFightingStyle() == fighting_style::dueling
			&& attacker.myUpgrades.WeaponLEquipped() && attacker.myUpgrades.WeaponREquipped())
		{
			total += 2;
		}

		if (total > 0)
		{
			target.subtract_health(total);
			std::cout << "\t" << attacker.get_name() << " did " << total << " damage to " << target.get_name() << std::endl;
		}
		else
			std::cout << "\t" << attacker.get_name() << " did 0 damage to " << target.get_name() << std::endl;
	}

	//else
	//{
	//	std::cout << target.get_name() << " is dead!" << std::endl;
	//}
}

void Attack::DealCriticalDamage(actor& attacker, actor& target, char hand, bool finesse)
{
	if (target.is_alive())
	{
		int total{};
		// left hand
		if (hand == 'L')
		{
			// check for finesse
			if (!finesse)
				total += (roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponL()) * 2) + attacker.get_strength_mod();
			else if (finesse)
				total += (roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponL()) * 2) + attacker.get_dex_mod();

			// check for resistance
			if (static_cast<int>(target.get_resistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
				&& static_cast<int>(target.get_resistance()) != 0)
			{
				total /= 2;
				std::cout << "\tDamage halved!" << std::endl;
			}
			// check for vulnerability
			if (static_cast<int>(target.get_vulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponL())
				&& static_cast<int>(target.get_vulnerability()) != 0)
			{
				total *= 2;
				std::cout << "\tDamage doubled!" << std::endl;
			}
		}
		// right hand
		else if (hand == 'R')
		{
			if (!finesse)
				total += (roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponR()) * 2) + attacker.get_strength_mod();
			else if (finesse)
				total += (roll_dice(1, attacker.myUpgrades.GetAttackDieWeaponR()) * 2) + attacker.get_dex_mod();

			// check for resistance
			if (static_cast<int>(target.get_resistance()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
				&& static_cast<int>(target.get_resistance()) != 0)
			{
				total /= 2;
				std::cout << "\tDamage halved!" << std::endl;
			}
			// check for vulnerability
			if (static_cast<int>(target.get_vulnerability()) == static_cast<int>(attacker.myUpgrades.GetAttackDamageTypeWeaponR())
				&& static_cast<int>(target.get_vulnerability()) != 0)
			{
				total *= 2;
				std::cout << "\tDamage doubled!" << std::endl;
			}
		}

		if (attacker.GetFightingStyle() == fighting_style::dueling)
		{
			total += 2;
		}

		if (total > 0)
		{
			target.subtract_health(total);
			std::cout << "\t" << attacker.get_name() << " did " << total << " damage to " << target.get_name() << std::endl;
		}
		else
			std::cout << "\t" << attacker.get_name() << " did 0 damage to " << target.get_name() << std::endl;
	}

	else
	{
		std::cout << target.get_name() << " is dead!" << std::endl;
	}
}

int Attack::CheckForAttackModifier(actor& attacker)
{
	int modifier{};

	if (attacker.get_combat_class() == character_class::fighter)
	{
		if (attacker.GetFightingStyle() == fighting_style::archery)
		{
			if (attacker.myUpgrades.RangedWeaponEquipped())
			{
				if(attacker.myUpgrades.rangedWeapon->GetWeaponType() == weapon_type::ranged)
					modifier = 2;
			}
		}
	}

	return modifier;
}

int Attack::CheckForACModifier(actor& target)
{
	int modifier{};

	if (target.get_combat_class() == character_class::fighter)
	{
		if (target.GetFightingStyle() == fighting_style::defense)
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

void Attack::LootCorpse(actor& attacker, actor& target)
{
	std::cout << "\t" << attacker.get_name() << " killed " << target.get_name() << "!" << std::endl;
	// loot the moneys
	attacker.myCurrency.add_money(target.myCurrency.get_copper());
	if (target.myCurrency.get_gold() >= 1)
		std::cout << "\t" << attacker.get_name() << " looted " << target.myCurrency.get_copper() / 100 << " gold!" << std::endl;
	if (target.myCurrency.get_gold() == 0 && target.myCurrency.get_silver() >= 1)
		std::cout << "\t" << attacker.get_name() << " looted " << target.myCurrency.get_copper() / 10 << " silver!" << std::endl;
	if (target.myCurrency.get_gold() == 0 && target.myCurrency.get_silver() == 0)
		std::cout << "\t" << attacker.get_name() << " looted " << target.myCurrency.get_copper() << " copper!" << std::endl;

	// get the XP gains
	int xpGain{ (rand() % 25 + 1) * target.get_level() };
	attacker.add_xp(xpGain);
	std::cout << "\t" << attacker.get_name() << " gained " << xpGain << " XP!" << std::endl;
}