#include "actor.h"

actor::actor()
{
	cout << "actor constructor called" << endl; // debug
}

actor::~actor()
{
	cout << "actor destructor called" << endl;
}

void Acactoror::Update()
{
	CheckLevelUpThreshold();
	UpdateArmorClass();
	UpdateAverageItemLevel();
}

void actor::update_armor_class()
{
	armorClass = myUpgrades.TotalArmorValue() + 10;
}

std::string actor::get_name()
{
	return this->name;
}

std::string actor::get_race()
{
	return this->race;
}

int actor::get_health()
{
	return this->health;
}

int actor::get_xp()
{
	return this->xp;
}

int actor::get_armor_class()
{
	return this->armorClass;
}

int actor::get_level()
{
	return this->level_;
}

int actor::get_proficiency()
{
	return this->proficiencyBonus;
}

int actor::get_strength()
{
	return this->strength;
}

int actor::get_dexterity()
{
	return this->dexterity;
}

int actor::get_constitution()
{
	return this->constitution;
}

int actor::get_intelligence()
{
	return this->intelligence;
}

int actor::get_wisdom()
{
	return this->wisdom;
}

int actor::get_charisma()
{
	return this->charisma;
}

int actor::get_strength_mod()
{
	int mod{ (this->strength - 10) / 2 };
	return mod;
}

int actor::get_dex_mod()
{
	int mod{ (this->dexterity - 10) / 2 };
	return mod;
}

int actor::get_const_mod()
{
	int mod{ (this->constitution - 10) / 2 };
	return mod;
}

int actor::get_intel_mod()
{
	int mod{ (this->intelligence - 10) / 2 };
	return mod;
}

int actor::get_wisdom_mod()
{
	int mod{ (this->wisdom - 10) / 2 };
	return mod;
}

int actor::get_char_mod()
{
	int mod{ (this->charisma - 10) / 2 };
	return mod;
}

int actor::get_passive_insight()
{
	int passiveInsight{ 10 + this->get_wisdom_mod() };
	return passiveInsight;
}

int actor::get_passive_perception()
{
	int passivePerception{ 10 + this->get_wisdom_mod() };
	return passivePerception;
}

int actor::get_passive_investigation()
{
	int passiveInvestigation{ 10 + this->get_intel_mod() };
	return passiveInvestigation;
}

damage_type actor::get_resistance()
{
	return resistance;
}

damage_type actor::get_vulnerability()
{
	return vulnerability;
}

int actor::get_initiative()
{
	return initiative;
}

bool actor::is_alive()
{
	return isAlive;
}

bool actor::is_dual_wielding()
{
	return isDualWielding;
}

bool actor::is_two_handed_melee()
{
	return isTwoHanded;
}

void actor::display()
{
	cout << endl;
	// name header
	cout << "====" << this->get_name() << "====" << endl;
	// basic stats
	cout << "   " << this->get_race() << endl;
	cout << "   " << this->get_health() << " HP / " << this->max_health_ << " HP" << endl;
	cout << "   " << (this->get_armor_class()) << " AC" << endl;
	cout << "   " << this->get_xp() << " XP" << endl;
	// ability stats
	cout << "   " << this->get_strength() << " Strength"
		<< " (" << this->get_strength_mod() << ")" << endl;
	cout << "   " << this->get_dexterity() << " Dexterity"
		<< " (" << this->get_dex_mod() << ")" << endl;
	cout << "   " << this->get_constitution() << " Constitution"
		<< " (" << this->get_const_mod() << ")" << endl;
	cout << "   " << this->get_intelligence() << " Intelligence"
		<< " (" << this->get_intel_mod() << ")" << endl;
	cout << "   " << this->get_wisdom() << " Wisdom"
		<< " (" << this->get_wisdom_mod() << ")" << endl;
	cout << "   " << this->get_charisma() << " Charisma"
		<< " (" << this->get_char_mod() << ")" << endl;
	// footer (matches length of header plus name)
	cout << "====";
	for (char c : this->get_name())
	{
		cout << "=";
	}
	cout << endl;
}

void actor::update_average_item_level()
{
	int totalUpgrades{};

	// armor
	if (this->myUpgrades.HelmetEquipped())
	{
		averageItemLevel += this->myUpgrades.helmet->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.ChestEquipped())
	{
		averageItemLevel += this->myUpgrades.chest->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.LegsEquipped())
	{
		averageItemLevel += this->myUpgrades.legs->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.HandsEquipped())
	{
		averageItemLevel += this->myUpgrades.hands->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.BootsEquipped())
	{
		averageItemLevel += this->myUpgrades.boots->GetLevel();
		totalUpgrades++;
	}

	// weapons and shield
	if (this->myUpgrades.WeaponLEquipped())
	{
		averageItemLevel += this->myUpgrades.weaponL->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.WeaponREquipped())
	{
		averageItemLevel += this->myUpgrades.weaponR->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.RangedWeaponEquipped())
	{
		averageItemLevel += this->myUpgrades.rangedWeapon->GetLevel();
		totalUpgrades++;
	}
	if (this->myUpgrades.ShieldEquipped())
	{
		averageItemLevel += this->myUpgrades.shield->GetLevel();
		totalUpgrades++;
	}

	if (totalUpgrades != 0)
		averageItemLevel /= totalUpgrades;
}
int actor::get_average_item_level()
{
	return averageItemLevel;
}

character_class actor::get_combat_class()
{
	return combatClass;
}

int actor::size_of_inventory()
{
	return this->myInventory.get_capacity();
}

void actor::use_potion()
{
	this->myInventory.display_potions();
	std::cout << "------------" << std::endl;
	std::cout << "0) to Exit" << std::endl;

	int choice{};
	bool valid_input{ false };

	do
	{
		std::cout << "Please enter a number: ";
		cin >> choice;

		if (!(valid_input = cin.good()) || choice > static_cast<int>(this->myInventory.potionInventory.size()) || choice < 0)
		{
			std::cout << "That's not a valid choice." << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || choice > static_cast<int>(this->myInventory.potionInventory.size()) || choice < 0);

	if (choice != 0)
	{
		this->add_health(this->myInventory.get_potion(choice)->GetHealthValue());
		this->myInventory.get_potion(choice)->Destroy();
		this->myInventory.remove_potion_from_inventory(this->myInventory.get_potion(choice));
	}
}

void actor::subtract_health(unsigned int damage)
{
	this->health -= damage;
	if (health <= 0)
		isAlive = false;
}

void actor::add_health(int healing)
{
	this->health += healing;
	if (health > max_health_)
		health = max_health_;
}

void actor::add_xp(int xpGain)
{
	this->xp += xpGain;
}

void actor::check_level_up_threshold()
{
	int levelTwo{ 300 };
	int levelThree{ 900 };
	int levelFour{ 2700 };
	int levelFive{ 6500 };

	if (this->get_xp() >= levelTwo)
	{
		this->level_up();
		cout << this->get_name() << " has reached LEVEL TWO!!!" << endl;
	}

	if (this->get_xp() >= levelThree)
	{
		this->level_up();
		cout << this->get_name() << " has reached LEVEL THREE!!!" << endl;
	}
	if (this->get_xp() >= levelFour)
	{
		this->level_up();
		cout << this->get_name() << " has reached LEVEL FOUR!!!" << endl;
	}
	if (this->get_xp() >= levelFive)
	{
		this->level_up();
		cout << this->get_name() << " has reached LEVEL FIVE!!!" << endl;
	}
}

//void actor::openInventory()
//{
//	myInventory.displayInventory();
//	
//	Menu* tempMenu = new Menu;
//	const int* decisions = new int{ 2 };
//	vector<string>* decisionList = new vector<string>{ "Equip Armor", "Exit" };
//
//	if (tempMenu->print_menu(*decisions, *decisionList) == 1)
//	{
//		EquipArmor(myInventory.selectItemInInventory());
//	}
//}

void actor::EquipHelmet(std::unique_ptr<Armor> helmet)
{
	myUpgrades.EquipHelmet(std::move(helmet));
}

void actor::EquipChest(std::unique_ptr<Armor> chest)
{
	myUpgrades.EquipChest(std::move(chest));
}

void actor::EquipLegs(std::unique_ptr<Armor> legs)
{
	myUpgrades.EquipLegs(std::move(legs));
}

void actor::EquipHands(std::unique_ptr<Armor> hands)
{
	myUpgrades.EquipHands(std::move(hands));
}

void actor::EquipBoots(std::unique_ptr<Armor> boots)
{
	myUpgrades.EquipBoots(std::move(boots));
}

void actor::EquipWeaponL(std::unique_ptr<Weapon> weaponL)
{
	myUpgrades.EquipWeaponL(std::move(weaponL));
	if (this->myUpgrades.WeaponREquipped())
		isDualWielding = true;
}

void actor::EquipRanged(std::unique_ptr<Weapon> rangedWeapon)
{
	myUpgrades.EquipRangedWeapon(std::move(rangedWeapon));
}

void actor::EquipWeaponR(std::unique_ptr<Weapon> weaponR)
{
	myUpgrades.EquipWeaponR(std::move(weaponR));
	if (this->myUpgrades.WeaponLEquipped())
		isDualWielding = true;
}

void actor::EquipShield(std::unique_ptr<Armor> shield)
{
	myUpgrades.EquipShield(std::move(shield));
}

void actor::ModifyStrength(const int& modifier)
{
	this->strength += modifier;
}

void actor::ModifyDexterity(const int& modifier)
{
	this->dexterity += modifier;
}

void actor::ModifyConstitution(const int& modifier)
{
	this->constitution += modifier;
}

void actor::ModifyIntelligence(const int& modifier)
{
	this->intelligence += modifier;
}

void actor::ModifyWisdom(const int& modifier)
{
	this->wisdom += modifier;
}

void actor::ModifyCharisma(const int& modifier)
{
	this->charisma += modifier;
}

void actor::RollForInitiative()
{
	initiative = roll_dice(1, 20) + this->get_dex_mod();
}

void actor::ClearInitiative()
{
	this->initiative = 0;
}

fighting_style actor::GetFightingStyle()
{
	return fightingStyle;
}
