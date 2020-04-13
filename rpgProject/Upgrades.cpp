#include "upgrades.h"

upgrades::upgrades()
{
	nothingEquipped = true;

	hasWeaponL = false;
	hasWeaponR = false;
	hasRangedWeapon = false;
	hasHelmet = false;
	hasChest = false;
	hasLegs = false;
	hasHands = false;
	hasBoots = false;
}

upgrades::~upgrades()
{
	weaponL = nullptr;
	weaponR = nullptr;
	rangedWeapon = nullptr;
	shield = nullptr;
	helmet = nullptr;
	chest = nullptr;
	legs = nullptr;
	hands = nullptr;
	boots = nullptr;
	std::cout << "upgrades destructor called" << std::endl; // debug
}

void upgrades::DisplayUpgrades()
{
	std::cout << "\n====UPGRADES EQUIPPED====" << std::endl;

	if (IsAnythingEquipped())
	{
		std::cout << "none" << std::endl;
	}
	else
	{
		// sword, ranged, and shield
		if (WeaponLEquipped() && WeaponREquipped())
		{
			std::cout << "Dual Wielding: " << std::endl;
			std::cout << "1) " << this->weaponL->GetName() <<
				", Level " << this->weaponL->GetLevel() <<
				" (d" << this->weaponL->GetAttackDieWeapon() << ")";

			if (this->weaponL->GetLevel() > 1)
			{
				std::cout << " +" <<
					this->weaponL->GetModifier() << " equipped" << std::endl;
			}
			else
				std::cout << " equipped" << std::endl;

			std::cout << "2) " << this->weaponR->GetName() <<
				", Level " << this->weaponR->GetLevel() <<
				" (d" << this->weaponR->GetAttackDieWeapon() << ")";

			if (this->weaponR->GetLevel() > 1)
			{
				std::cout << " +" <<
					this->weaponR->GetModifier() << " equipped" << std::endl;
			}
			else
				std::cout << " equipped" << std::endl;
		}

		else if (RangedWeaponEquipped())
		{
			std::cout << this->rangedWeapon->GetName() <<
				", Level " << this->rangedWeapon->GetLevel() <<
				" (d" << this->rangedWeapon->GetAttackDieWeapon() << ")";

			if (this->rangedWeapon->GetLevel() > 1)
			{
				std::cout << " +" <<
					this->rangedWeapon->GetModifier() << " equipped" << std::endl;
			}
			else
				std::cout << " equipped" << std::endl;
		}

		else if (WeaponLEquipped())
		{
			std::cout << this->weaponL->GetName() <<
				", Level " << this->weaponL->GetLevel() <<
				" (d" << this->weaponL->GetAttackDieWeapon() << ")";

			if (this->weaponL->GetLevel() > 1)
			{
				std::cout << " +" <<
					this->weaponL->GetModifier() << " equipped" << std::endl;
			}
			else
				std::cout << " equipped" << std::endl;
		}
		else if (WeaponREquipped())
		{
			std::cout << this->weaponR->GetName() <<
				", Level " << this->weaponR->GetLevel() <<
				" (d" << this->weaponR->GetAttackDieWeapon() << ")";

			if (this->weaponR->GetLevel() > 1)
			{
				std::cout << " +" <<
					this->weaponR->GetModifier() << " equipped" << std::endl;
			}
			else
				std::cout << " equipped" << std::endl;
		}
		if (ShieldEquipped())
			std::cout << this->shield->GetName() <<
			", Level " << this->shield->GetLevel() <<
			" (+" << this->shield->GetArmorValue() << "AC) equipped" << std::endl;

		// armor
		if (HelmetEquipped())
			std::cout << this->helmet->GetName() <<
			", Level " << this->helmet->GetLevel() <<
			" (+" << this->helmet->GetArmorValue() << "AC) equipped" << std::endl;
		if (ChestEquipped())
			std::cout << this->chest->GetName() <<
			", Level " << this->chest->GetLevel() <<
			" (+" << this->chest->GetArmorValue() << "AC) equipped" << std::endl;
		if (LegsEquipped())
			std::cout << this->legs->GetName() <<
			", Level " << this->legs->GetLevel() <<
			" (+" << this->legs->GetArmorValue() << "AC) equipped" << std::endl;
		if (HandsEquipped())
			std::cout << this->hands->GetName() <<
			", Level " << this->hands->GetLevel() <<
			" (+" << this->hands->GetArmorValue() << "AC) equipped" << std::endl;
		if (BootsEquipped())
			std::cout << this->boots->GetName() <<
			", Level " << this->boots->GetLevel() <<
			" (+" << this->boots->GetArmorValue() << "AC) equipped" << std::endl;
	}
	
	std::cout << "=======================" << std::endl;
}

int upgrades::TotalArmorValue()
{
	int total{};

	if (HelmetEquipped())
		total += this->helmet->GetArmorValue();
	if (ChestEquipped())
		total += this->chest->GetArmorValue();
	if (LegsEquipped())
		total += this->legs->GetArmorValue();
	if (HandsEquipped())
		total += this->hands->GetArmorValue();
	if (BootsEquipped())
		total += this->boots->GetArmorValue();
	if (ShieldEquipped())
		total += this->shield->GetArmorValue();

	return total;
}

bool upgrades::HelmetEquipped()
{
	return hasHelmet;
}

bool upgrades::ChestEquipped()
{
	return hasChest;
}

bool upgrades::LegsEquipped()
{
	return hasLegs;
}

bool upgrades::HandsEquipped()
{
	return hasHands;
}

bool upgrades::BootsEquipped()
{
	return hasBoots;
}

int upgrades::GetHelmetLevel()
{
	return this->helmet->GetLevel();
}

int upgrades::GetChestLevel()
{
	return this->chest->GetLevel();
}

int upgrades::GetLegsLevel()
{
	return this->legs->GetLevel();
}

int upgrades::GetHandsLevel()
{
	return this->hands->GetLevel();
}

int upgrades::GetBootsLevel()
{
	return this->boots->GetLevel();
}

bool upgrades::WeaponLEquipped()
{
	return hasWeaponL;
}

bool upgrades::WeaponREquipped()
{
	return hasWeaponR;
}

bool upgrades::RangedWeaponEquipped()
{
	return hasRangedWeapon;
}

int upgrades::GetWeaponLLevel()
{
	return this->weaponL->GetLevel();
}

int upgrades::GetShieldLevel()
{
	return this->shield->GetLevel();
}

int upgrades::GetWeaponRLevel()
{
	return this->weaponR->GetLevel();
}

int upgrades::GetRangedWeaponLevel()
{
	return this->rangedWeapon->GetLevel();
}

int upgrades::GetAttackDieWeaponL()
{
	if (hasWeaponL)
		return weaponL->GetAttackDieWeapon();
	else
		return unarmedAttackDie;
}

int upgrades::GetAttackDieWeaponR()
{
	if (hasWeaponR)
		return weaponR->GetAttackDieWeapon();
	else
		return unarmedAttackDie;
}

int upgrades::GetRangedAttackDie()
{
	if (hasRangedWeapon)
		return rangedWeapon->GetAttackDieWeapon();
	else
		return unarmedAttackDie;
}

damage_type upgrades::GetAttackDamageTypeWeaponL()
{
	if (hasWeaponL)
		return weaponL->GetDamageType();
	else
		return damage_type::none;
}

damage_type upgrades::GetAttackDamageTypeWeaponR()
{
	if (hasWeaponR)
		return weaponR->GetDamageType();
	else
		return damage_type::none;
}

damage_type upgrades::GetRangedAttackDamageType()
{
	if (hasRangedWeapon)
		return rangedWeapon->GetDamageType();
	else
		return damage_type::none;
}

bool upgrades::IsDualWielding()
{
	if (hasWeaponL && hasWeaponR)
	{
		isDualWielding = true;
	}
	else
	{
		isDualWielding = false;
	}

	return isDualWielding;
}

bool upgrades::IsRangedWeapon()
{
	return hasRangedWeapon;
}

bool upgrades::ShieldEquipped()
{
	return hasShield;
}

void upgrades::EquipWeaponL(std::unique_ptr<Weapon> weaponL)
{
	if (ShieldEquipped() && WeaponREquipped())
		std::cout << "No free hand to equip a second weapon." << std::endl;
	else if (RangedWeaponEquipped())
		std::cout << "No free hand to equip a weapon." << std::endl;
	else
	{
		this->weaponL = std::move(weaponL);
		hasWeaponL = true;
	}
}

void upgrades::EquipWeaponR(std::unique_ptr<Weapon> weaponR)
{
	if (ShieldEquipped() && WeaponLEquipped())
		std::cout << "No free hand to equip a second weapon." << std::endl;
	else if (RangedWeaponEquipped())
		std::cout << "No free hand to equip a weapon." << std::endl;
	else
	{
		this->weaponR = std::move(weaponR);
		hasWeaponR = true;
	}

}

void upgrades::EquipRangedWeapon(std::unique_ptr<Weapon> rangedWeapon)
{
	if (!ShieldEquipped() && !WeaponLEquipped() && !WeaponREquipped())
	{
		this->rangedWeapon = std::move(rangedWeapon);
		hasRangedWeapon = true;
	}
	else
		std::cout << "No free hand to equip a ranged weapon." << std::endl;
}

void upgrades::UnequipWeaponL()
{
	this->weaponL = nullptr;
	hasWeaponL = false;
}

void upgrades::UnequipWeaponR()
{
	this->weaponR = nullptr;
	hasWeaponR = false;
}

void upgrades::UnequipRangedWeapon()
{
	this->rangedWeapon = nullptr;
	hasRangedWeapon = false;
}

void upgrades::EquipShield(std::unique_ptr<Armor> shield)
{
	if (WeaponLEquipped() && WeaponREquipped() || RangedWeaponEquipped())
		std::cout << "No free hand to equip a shield." << std::endl;
	else
	{
		this->shield = std::move(shield);
		hasShield = true;
	}
}

void upgrades::UnequipShield()
{
	this->shield = nullptr;
	hasShield = false;
}

void upgrades::EquipHelmet(std::unique_ptr<Armor> helmet)
{
	this->helmet = std::move(helmet);
	hasHelmet = true;
}

void upgrades::EquipChest(std::unique_ptr<Armor> chest)
{
	this->chest = std::move(chest);
	hasChest = true;
}

void upgrades::EquipLegs(std::unique_ptr<Armor> legs)
{
	this->legs = std::move(legs);
	hasLegs = true;
}

void upgrades::EquipHands(std::unique_ptr<Armor> hands)
{
	this->hands = std::move(hands);
	hasHands = true;
}

void upgrades::EquipBoots(std::unique_ptr<Armor> boots)
{
	this->boots = std::move(boots);
	hasBoots = true;
}

void upgrades::UnequipHelmet()
{
	this->helmet = nullptr;
	hasHelmet = false;
}

void upgrades::UnequipChest()
{
	this->chest = nullptr;
	hasChest = false;
}

void upgrades::UnequipLegs()
{
	this->legs = nullptr;
	hasLegs = false;
}

void upgrades::UnequipHands()
{
	this->hands = nullptr;
	hasHands = false;
}

void upgrades::UnequipBoots()
{
	this->boots = nullptr;
	hasBoots = false;
}

bool upgrades::IsAnythingEquipped()
{
	if (!HelmetEquipped() &&
		!ChestEquipped() &&
		!LegsEquipped() &&
		!HandsEquipped() &&
		!BootsEquipped() &&
		!WeaponLEquipped() &&
		!WeaponREquipped() &&
		!RangedWeaponEquipped() &&
		!ShieldEquipped()
		)
	{
		nothingEquipped = true;
	}
	else
	{
		nothingEquipped = false;
	}

	return nothingEquipped;
}
