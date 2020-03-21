#include "Actor.h"

Actor::Actor()
{
	cout << "Actor constructor called" << endl; // debug
}

Actor::~Actor()
{
	cout << "Actor destructor called" << endl;
}

void Actor::Update()
{
	CheckLevelUpThreshold();
	UpdateArmorClass();
	UpdateAverageItemLevel();
}

void Actor::UpdateArmorClass()
{
	armorClass = myUpgrades.TotalArmorValue() + 10;
}

string Actor::GetName()
{
	return this->name;
}

string Actor::GetRace()
{
	return this->race;
}

int Actor::GetHealth()
{
	return this->health;
}

int Actor::GetXP()
{
	return this->xp;
}

int Actor::GetArmorClass()
{
	return this->armorClass;
}

int Actor::GetLevel()
{
	return this->level;
}

int Actor::GetProficiency()
{
	return this->proficiencyBonus;
}

int Actor::GetStrength()
{
	return this->strength;
}

int Actor::GetDexterity()
{
	return this->dexterity;
}

int Actor::GetConstitution()
{
	return this->constitution;
}

int Actor::GetIntelligence()
{
	return this->intelligence;
}

int Actor::GetWisdom()
{
	return this->wisdom;
}

int Actor::GetCharisma()
{
	return this->charisma;
}

int Actor::GetStrengthMod()
{
	int mod{ (this->strength - 10) / 2 };
	return mod;
}

int Actor::GetDexMod()
{
	int mod{ (this->dexterity - 10) / 2 };
	return mod;
}

int Actor::GetConstMod()
{
	int mod{ (this->constitution - 10) / 2 };
	return mod;
}

int Actor::GetIntelMod()
{
	int mod{ (this->intelligence - 10) / 2 };
	return mod;
}

int Actor::GetWisdomMod()
{
	int mod{ (this->wisdom - 10) / 2 };
	return mod;
}

int Actor::GetCharMod()
{
	int mod{ (this->charisma - 10) / 2 };
	return mod;
}

int Actor::GetPassiveInsight()
{
	int passiveInsight{ 10 + this->GetWisdomMod() };
	return passiveInsight;
}

int Actor::GetPassivePerception()
{
	int passivePerception{ 10 + this->GetWisdomMod() };
	return passivePerception;
}

int Actor::GetPassiveInvestigation()
{
	int passiveInvestigation{ 10 + this->GetIntelMod() };
	return passiveInvestigation;
}

DAMAGE_TYPE Actor::GetResistance()
{
	return resistance;
}

DAMAGE_TYPE Actor::GetVulnerability()
{
	return vulnerability;
}

int Actor::GetInitiative()
{
	return initiative;
}

bool Actor::LivingOrDead()
{
	return isAlive;
}

void Actor::Display()
{
	cout << endl;
	// name header
	cout << "====" << this->GetName() << "====" << endl;
	// basic stats
	cout << "   " << this->GetRace() << endl;
	cout << "   " << this->GetHealth() << " HP / " << this->maxHealth << " HP" << endl;
	cout << "   " << (this->GetArmorClass()) << " AC" << endl;
	cout << "   " << this->GetXP() << " XP" << endl;
	// ability stats
	cout << "   " << this->GetStrength() << " Strength"
		<< " (" << this->GetStrengthMod() << ")" << endl;
	cout << "   " << this->GetDexterity() << " Dexterity"
		<< " (" << this->GetDexMod() << ")" << endl;
	cout << "   " << this->GetConstitution() << " Constitution"
		<< " (" << this->GetConstMod() << ")" << endl;
	cout << "   " << this->GetIntelligence() << " Intelligence"
		<< " (" << this->GetIntelMod() << ")" << endl;
	cout << "   " << this->GetWisdom() << " Wisdom"
		<< " (" << this->GetWisdomMod() << ")" << endl;
	cout << "   " << this->GetCharisma() << " Charisma"
		<< " (" << this->GetCharMod() << ")" << endl;
	// footer (matches length of header plus name)
	cout << "====";
	for (char c : this->GetName())
	{
		cout << "=";
	}
	cout << endl;
}

void Actor::UpdateAverageItemLevel()
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

	// weapons and shiled
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
	if (this->myUpgrades.ShieldEquipped())
	{
		averageItemLevel += this->myUpgrades.shield->GetLevel();
		totalUpgrades++;
	}

	if (totalUpgrades != 0)
		averageItemLevel /= totalUpgrades;
}
int Actor::GetAverageItemLevel()
{
	return averageItemLevel;
}

COMBAT_CLASS Actor::GetCombatClass()
{
	return combatClass;
}

int Actor::SizeOfInventory()
{
	return this->myInventory.GetCapacity();
}

void Actor::UsePotion()
{
	this->myInventory.DisplayPotions();
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
		this->AddHealth(this->myInventory.GetPotion(choice)->GetHealthValue());
		this->myInventory.GetPotion(choice)->Destroy();
		this->myInventory.RemovePotionFromInventory(this->myInventory.GetPotion(choice));
	}
}

void Actor::SubtractHealth(unsigned int damage)
{
	this->health -= damage;
	if (health <= 0)
		isAlive = false;
}

void Actor::AddHealth(int healing)
{
	this->health += healing;
	if (health > maxHealth)
		health = maxHealth;
}

void Actor::AddXP(int xpGain)
{
	this->xp += xpGain;
}

void Actor::CheckLevelUpThreshold()
{
	int levelTwo{ 300 };
	int levelThree{ 900 };
	int levelFour{ 2700 };
	int levelFive{ 6500 };

	if (this->GetXP() >= levelTwo)
	{
		this->LevelUp();
		cout << this->GetName() << " has reached LEVEL TWO!!!" << endl;
	}

	if (this->GetXP() >= levelThree)
	{
		this->LevelUp();
		cout << this->GetName() << " has reached LEVEL THREE!!!" << endl;
	}
	if (this->GetXP() >= levelFour)
	{
		this->LevelUp();
		cout << this->GetName() << " has reached LEVEL FOUR!!!" << endl;
	}
	if (this->GetXP() >= levelFive)
	{
		this->LevelUp();
		cout << this->GetName() << " has reached LEVEL FIVE!!!" << endl;
	}
}

//void Actor::openInventory()
//{
//	myInventory.displayInventory();
//	
//	Menu* tempMenu = new Menu;
//	const int* decisions = new int{ 2 };
//	vector<string>* decisionList = new vector<string>{ "Equip Armor", "Exit" };
//
//	if (tempMenu->PrintMenu(*decisions, *decisionList) == 1)
//	{
//		EquipArmor(myInventory.selectItemInInventory());
//	}
//}

void Actor::EquipHelmet(std::unique_ptr<Armor> helmet)
{
	myUpgrades.EquipHelmet(std::move(helmet));
}

void Actor::EquipChest(std::unique_ptr<Armor> chest)
{
	myUpgrades.EquipChest(std::move(chest));
}

void Actor::EquipLegs(std::unique_ptr<Armor> legs)
{
	myUpgrades.EquipLegs(std::move(legs));
}

void Actor::EquipHands(std::unique_ptr<Armor> hands)
{
	myUpgrades.EquipHands(std::move(hands));
}

void Actor::EquipBoots(std::unique_ptr<Armor> boots)
{
	myUpgrades.EquipBoots(std::move(boots));
}

void Actor::EquipWeaponL(std::unique_ptr<Weapon> weaponL)
{
	myUpgrades.EquipWeaponL(std::move(weaponL));
}

void Actor::EquipRanged(std::unique_ptr<Weapon> rangedWeapon)
{
	myUpgrades.EquipRangedWeapon(std::move(rangedWeapon));
}

void Actor::EquipWeaponR(std::unique_ptr<Weapon> weaponR)
{
	myUpgrades.EquipWeaponR(std::move(weaponR));
}

void Actor::EquipShield(std::unique_ptr<Armor> shield)
{
	myUpgrades.EquipShield(std::move(shield));
}

void Actor::ModifyStrength(const int& modifier)
{
	this->strength += modifier;
}

void Actor::ModifyDexterity(const int& modifier)
{
	this->dexterity += modifier;
}

void Actor::ModifyConstitution(const int& modifier)
{
	this->constitution += modifier;
}

void Actor::ModifyIntelligence(const int& modifier)
{
	this->intelligence += modifier;
}

void Actor::ModifyWisdom(const int& modifier)
{
	this->wisdom += modifier;
}

void Actor::ModifyCharisma(const int& modifier)
{
	this->charisma += modifier;
}

void Actor::RollForInitiative()
{
	initiative = RollDice(1, 20) + this->GetDexMod();
}

void Actor::ClearInitiative()
{
	this->initiative = 0;
}

FIGHTING_STYLE Actor::GetFightingStyle()
{
	return fightingStyle;
}
