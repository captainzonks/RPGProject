#include "Upgrades.h"

Upgrades::Upgrades()
{
	hasHelmet = false;
	hasChest = false;
	hasLegs = false;
	hasHands = false;
	hasBoots = false;
}

Upgrades::~Upgrades()
{
	weapon = nullptr;
	shield = nullptr;
	helmet = nullptr;
	chest = nullptr;
	legs = nullptr;
	hands = nullptr;
	boots = nullptr;
	std::cout << "Upgrades destructor called" << std::endl; // debug
}

void Upgrades::DisplayUpgrades()
{
	std::cout << "\n===UPGRADES EQUIPPED===" << std::endl;
	// sword and shield
	if (WeaponEquipped())
	{
		std::cout << this->weapon->GetName() <<
			", Level " << this->weapon->GetLevel() <<
			" (d" << this->weapon->GetAttackDie() << ")";

		if (this->weapon->GetLevel() > 1)
		{
			std::cout << " +" <<
				this->weapon->GetModifier() << " equipped" << std::endl;
		}
		else
			std:: cout << " equipped" << std::endl;
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

	std::cout << "=======================" << std::endl;
}

int Upgrades::TotalArmorValue()
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

bool Upgrades::HelmetEquipped()
{
	return hasHelmet;
}

bool Upgrades::ChestEquipped()
{
	return hasChest;
}

bool Upgrades::LegsEquipped()
{
	return hasLegs;
}

bool Upgrades::HandsEquipped()
{
	return hasHands;
}

bool Upgrades::BootsEquipped()
{
	return hasBoots;
}

int Upgrades::GetHelmetLevel()
{
	return this->helmet->GetLevel();
}

int Upgrades::GetChestLevel()
{
	return this->chest->GetLevel();
}

int Upgrades::GetLegsLevel()
{
	return this->legs->GetLevel();
}

int Upgrades::GetHandsLevel()
{
	return this->hands->GetLevel();
}

int Upgrades::GetBootsLevel()
{
	return this->boots->GetLevel();
}

bool Upgrades::WeaponEquipped()
{
	return hasWeapon;
}

int Upgrades::GetWeaponLevel()
{
	return this->weapon->GetLevel();
}

int Upgrades::GetShieldLevel()
{
	return this->shield->GetLevel();
}

int Upgrades::GetAttackDie()
{
	if (hasWeapon)
		return weapon->GetAttackDie();
	else
		return unarmedAttackDie;
}

DAMAGE_TYPE Upgrades::GetAttackDamageType()
{
	if (hasWeapon)
		return weapon->GetDamageType();
	else
		return DAMAGE_TYPE::NONE;
}

bool Upgrades::ShieldEquipped()
{
	return hasShield;
}

void Upgrades::EquipWeapon(std::unique_ptr<Weapon> weapon)
{
	this->weapon = std::move(weapon);
	hasWeapon = true;
}

void Upgrades::UnequipWeapon()
{
	this->weapon = nullptr;
	hasWeapon = false;
}

void Upgrades::EquipShield(std::unique_ptr<Armor> shield)
{
	this->shield = std::move(shield);
	hasShield = true;
}

void Upgrades::UnequipShield()
{
	this->shield = nullptr;
	hasShield = false;
}

void Upgrades::EquipHelmet(std::unique_ptr<Armor> helmet)
{
	this->helmet = std::move(helmet);
	hasHelmet = true;
}

void Upgrades::EquipChest(std::unique_ptr<Armor> chest)
{
	this->chest = std::move(chest);
	hasChest = true;
}

void Upgrades::EquipLegs(std::unique_ptr<Armor> legs)
{
	this->legs = std::move(legs);
	hasLegs = true;
}

void Upgrades::EquipHands(std::unique_ptr<Armor> hands)
{
	this->hands = std::move(hands);
	hasHands = true;
}

void Upgrades::EquipBoots(std::unique_ptr<Armor> boots)
{
	this->boots = std::move(boots);
	hasBoots = true;
}

void Upgrades::UnequipHelmet()
{
	this->helmet = nullptr;
	hasHelmet = false;
}

void Upgrades::UnequipChest()
{
	this->chest = nullptr;
	hasChest = false;
}

void Upgrades::UnequipLegs()
{
	this->legs = nullptr;
	hasLegs = false;
}

void Upgrades::UnequipHands()
{
	this->hands = nullptr;
	hasHands = false;
}

void Upgrades::UnequipBoots()
{
	this->boots = nullptr;
	hasBoots = false;
}
