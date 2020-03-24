#include "Fighter.h"

// Player Constructor
Fighter::Fighter(std::string name, std::string race)
{
	std::cout << "Player Fighter constructor called" << std::endl;

	this->name = name;
	this->race = race;
	this->combatClass = COMBAT_CLASS::FIGHTER;
	this->savingThrows = { ABILITIES::STRENGTH, ABILITIES::CONSTITUTION };

	if (race == "Human")
	{
		RollHumanStats();
	}
	else if (race == "Dwarf")
	{
		RollDwarfStats();
		this->walkingSpeed = 25;
	}
	else if (race == "Elf")
	{
		RollElfStats();
	}
	else if (race == "Halfling")
	{
		RollHalflingStats();
		this->walkingSpeed = 25;
	}

	this->xp = 0;
	this->level = 1;
	this->myCurrency.AddMoney(RollDice(4, 4) * 10000);

	SetFightingStyle();
	this->hitDice = 10;
	this->hitDiceQuantity = 1;
	this->health = GetHitDice() + GetConstMod();
	this->maxHealth = health;
}

Fighter::Fighter(int identifier)
{
	std::cout << "Bad Guy Fighter constructor called" << std::endl;

	this->identifier = identifier;
	this->combatClass = COMBAT_CLASS::FIGHTER;
	this->savingThrows = { ABILITIES::STRENGTH, ABILITIES::CONSTITUTION };

	int randomRaceChoice{ rand() % 4 + 1 };
	if (randomRaceChoice == 1)
	{
		this->race = "Human";
		RollHumanStats();
	}
	else if (randomRaceChoice == 2)
	{
		this->race = "Dwarf";
		RollDwarfStats();
	}
	else if (randomRaceChoice == 3)
	{
		this->race = "Elf";
		RollElfStats();
	}
	else if (randomRaceChoice == 4)
	{
		this->race = "Halfling";
		RollHalflingStats();
	}

	this->name = "Bad Guy " + std::to_string(identifier) + " (" + race + ")";
	this->xp = 0;
	this->level = 1;
	this->myCurrency.AddMoney(RollDice(4, 4) * 10);

	SetEnemyFightingStyle();
	this->hitDice = 10;
	this->hitDiceQuantity = 1;
	this->health = GetHitDice() + GetConstMod();
	this->maxHealth = health;
}

Fighter::~Fighter()
{
	std::cout << "Fighter destructor called" << std::endl; // debug
}

void Fighter::RollHumanStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6) + 1;
	this->dexterity = RollDiceIgnoreLowest(4, 6) + 1;
	this->constitution = RollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = RollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

void Fighter::RollDwarfStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6) + 2;
	this->dexterity = RollDiceIgnoreLowest(4, 6);
	this->constitution = RollDiceIgnoreLowest(4, 6) + 2;
	this->intelligence = RollDiceIgnoreLowest(4, 6);
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6);
}

void Fighter::RollElfStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6);
	this->dexterity = RollDiceIgnoreLowest(4, 6) + 2;
	this->constitution = RollDiceIgnoreLowest(4, 6);
	this->intelligence = RollDiceIgnoreLowest(4, 6) + 1;
	this->wisdom = RollDiceIgnoreLowest(4, 6) + 1;
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

void Fighter::RollHalflingStats()
{
	this->strength = RollDiceIgnoreLowest(4, 6);
	this->dexterity = RollDiceIgnoreLowest(4, 6);
	this->constitution = RollDiceIgnoreLowest(4, 6) + 1;
	this->intelligence = RollDiceIgnoreLowest(4, 6);
	this->wisdom = RollDiceIgnoreLowest(4, 6);
	this->charisma = RollDiceIgnoreLowest(4, 6) + 1;
}

void Fighter::SetFightingStyle()
{
	std::cout << "\nWhat Fighting Style are you?" << std::endl;

	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(6);
	std::unique_ptr<vector<std::string>> tempDecisions = 
		std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
			{ "Archery", "Defense", "Dueling", "Great Weapon Fighting", "Protection", "Two Weapon Fighting" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	if (choice == 1)
	{
		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<std::string>> tempDecisions =
			std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
				{ "Learn more about Archery", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "\n==Archery==" << std::endl;
			std::cout << "You gain a +2 bonus to attack rolls" << std::endl;
			std::cout << "you make with ranged weapons." << std::endl;
			std::cout << "-----------" << std::endl;
			
			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<std::string>> tempDecisions =
				std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
					{ "Pick this Fighting Style", "Choose a different Fighting Style" }));
			choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

			if (choice == 1)
				fightingStyle = FIGHTING_STYLE::ARCHERY;
			else
				SetFightingStyle();
		}
		fightingStyle = FIGHTING_STYLE::ARCHERY;
	}
	else if (choice == 2)
	{
		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<std::string>> tempDecisions =
			std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
				{ "Learn more about Defense", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "\n==Defense==" << std::endl;
			std::cout << "While you are wearing armor," << std::endl;
			std::cout << "you gain a +1 bonus to AC." << std::endl;
			std::cout << "-----------" << std::endl;

			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<std::string>> tempDecisions =
				std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
					{ "Pick this Fighting Style", "Choose a different Fighting Style" }));
			choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

			if (choice == 1)
				fightingStyle = FIGHTING_STYLE::DEFENSE;
			else
				SetFightingStyle();
		}
		fightingStyle = FIGHTING_STYLE::DEFENSE;
	}
	else if (choice == 3)
	{
		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<std::string>> tempDecisions =
			std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
				{ "Learn more about Dueling", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "\n==Dueling==" << std::endl;
			std::cout << "When you are wielding a melee" << std::endl;
			std::cout << "weapon in one hand and no other" << std::endl;
			std::cout << "weapons, you gain a +2 bonus to" << std::endl;
			std::cout << "damage rolls with that weapon." << std::endl;
			std::cout << "-----------" << std::endl;

			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<std::string>> tempDecisions =
				std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
					{ "Pick this Fighting Style", "Choose a different Fighting Style" }));
			choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

			if (choice == 1)
				fightingStyle = FIGHTING_STYLE::DUELING;
			else
				SetFightingStyle();
		}
		fightingStyle = FIGHTING_STYLE::DUELING;
	}
	else if (choice == 4)
	{
		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<std::string>> tempDecisions =
			std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
				{ "Learn more about Great Weapon Fighting", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "\n==Great Weapon Fighting==" << std::endl;
			std::cout << "When you roll a 1 or 2 on a damage" << std::endl;
			std::cout << "die for an attack you make with a" << std::endl;
			std::cout << "melee weapon that you are wielding with" << std::endl;
			std::cout << "two hands, you can reroll the die and must" << std::endl;
			std::cout << "use the new roll, even if the new roll is" << std::endl;
			std::cout << "a 1 or a 2. The weapon must have the" << std::endl;
			std::cout << "two-handed or versatile property for you" << std::endl;
			std::cout << "to gain this benefit." << std::endl;
			std::cout << "-----------" << std::endl;

			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<std::string>> tempDecisions =
				std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
					{ "Pick this Fighting Style", "Choose a different Fighting Style" }));
			choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

			if (choice == 1)
				fightingStyle = FIGHTING_STYLE::GREAT_WEAPON_FIGHTING;
			else
				SetFightingStyle();
		}
		fightingStyle = FIGHTING_STYLE::GREAT_WEAPON_FIGHTING;
	}
	else if (choice == 5)
	{
	choice = 0;
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(2);
	std::unique_ptr<vector<std::string>> tempDecisions =
		std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
			{ "Learn more about Protection", "Choose this Fighting Style" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	if (choice == 1)
	{
		std::cout << "\n==Protection==" << std::endl;
		std::cout << "When a creature you can see attacks a" << std::endl;
		std::cout << "target other than you that is within" << std::endl;
		std::cout << "5 feet of you, you can use your reaction" << std::endl;
		std::cout << "to impose disadvantage on the attack roll." << std::endl;
		std::cout << "You must be wielding a shield." << std::endl;
		std::cout << "-----------" << std::endl;

		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<std::string>> tempDecisions =
			std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
				{ "Pick this Fighting Style", "Choose a different Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
			fightingStyle = FIGHTING_STYLE::PROTECTION;
		else
			SetFightingStyle();
	}
	fightingStyle = FIGHTING_STYLE::PROTECTION;
	}
	else if (choice == 6)
	{
	choice = 0;
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(2);
	std::unique_ptr<vector<std::string>> tempDecisions =
		std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
			{ "Learn more about Two-Weapon Fighting", "Choose this Fighting Style" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	if (choice == 1)
	{
		std::cout << "\n==Two-Weapon Fighting==" << std::endl;
		std::cout << "When you engage in two-weapon fighting," << std::endl;
		std::cout << "you can add your ability modifier to" << std::endl;
		std::cout << "the damage of the second attack." << std::endl;
		std::cout << "-----------" << std::endl;

		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<std::string>> tempDecisions =
			std::make_unique<vector<std::string>>(std::initializer_list<std::string>(
				{ "Pick this Fighting Style", "Choose a different Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
			fightingStyle = FIGHTING_STYLE::TWO_WEAPON_FIGHTING;
		else
			SetFightingStyle();
	}
	fightingStyle = FIGHTING_STYLE::TWO_WEAPON_FIGHTING;
	}

}

void Fighter::SetEnemyFightingStyle()
{
	int randomFightingStyle{ rand() % 6 + 1 };

	if (randomFightingStyle == 1)
		this->fightingStyle = FIGHTING_STYLE::ARCHERY;
	else if (randomFightingStyle == 2)
		this->fightingStyle = FIGHTING_STYLE::DEFENSE;
	else if (randomFightingStyle == 3)
		this->fightingStyle = FIGHTING_STYLE::DUELING;
	else if (randomFightingStyle == 4)
		this->fightingStyle = FIGHTING_STYLE::GREAT_WEAPON_FIGHTING;
	else if (randomFightingStyle == 5)
		this->fightingStyle = FIGHTING_STYLE::PROTECTION;
	else if (randomFightingStyle == 6)
		this->fightingStyle = FIGHTING_STYLE::TWO_WEAPON_FIGHTING;
}

void Fighter::DisplayClassInformation()
{
	std::cout << "\n\n******FIGHTER lvl " + this->GetLevel() << "******" << std::endl;
	if (fightingStyle == FIGHTING_STYLE::ARCHERY)
	{
		std::cout << "\n==Archery==" << std::endl;
		std::cout << "You gain a +2 bonus to attack rolls" << std::endl;
		std::cout << "you make with ranged weapons." << std::endl;
		std::cout << "-----------" << std::endl;
	}
	if (fightingStyle == FIGHTING_STYLE::DEFENSE)
	{
		std::cout << "\n==Defense==" << std::endl;
		std::cout << "While you are wearing armor," << std::endl;
		std::cout << "you gain a +1 bonus to AC." << std::endl;
		std::cout << "-----------" << std::endl;
	}
	if (fightingStyle == FIGHTING_STYLE::DUELING)
	{
		std::cout << "\n==Dueling==" << std::endl;
		std::cout << "When you are wielding a melee" << std::endl;
		std::cout << "weapon in one hand and no other" << std::endl;
		std::cout << "weapons, you gain a +2 bonus to" << std::endl;
		std::cout << "damage rolls with that weapon." << std::endl;
		std::cout << "-----------" << std::endl;
	}
	if (fightingStyle == FIGHTING_STYLE::GREAT_WEAPON_FIGHTING)
	{
		std::cout << "\n==Great Weapon Fighting==" << std::endl;
		std::cout << "When you roll a 1 or 2 on a damage" << std::endl;
		std::cout << "die for an attack you make with a" << std::endl;
		std::cout << "melee weapon that you are wielding with" << std::endl;
		std::cout << "two hands, you can reroll the die and must" << std::endl;
		std::cout << "use the new roll, even if the new roll is" << std::endl;
		std::cout << "a 1 or a 2. The weapon must have the" << std::endl;
		std::cout << "two-handed or versatile property for you" << std::endl;
		std::cout << "to gain this benefit." << std::endl;
		std::cout << "-----------" << std::endl;
	}
	if (fightingStyle == FIGHTING_STYLE::PROTECTION)
	{
		std::cout << "\n==Protection==" << std::endl;
		std::cout << "When a creature you can see attacks a" << std::endl;
		std::cout << "target other than you that is within" << std::endl;
		std::cout << "5 feet of you, you can use your reaction" << std::endl;
		std::cout << "to impose disadvantage on the attack roll." << std::endl;
		std::cout << "You must be wielding a shield." << std::endl;
		std::cout << "-----------" << std::endl;
	}
	if (fightingStyle == FIGHTING_STYLE::TWO_WEAPON_FIGHTING)
	{
		std::cout << "\n==Two-Weapon Fighting==" << std::endl;
		std::cout << "When you engage in two-weapon fighting," << std::endl;
		std::cout << "you can add your ability modifier to" << std::endl;
		std::cout << "the damage of the second attack." << std::endl;
		std::cout << "-----------" << std::endl;
	}
}

void Fighter::LevelUp()
{
	this->maxHealth += RollDice(1, GetHitDice()) + GetConstMod();
	this->health = this->maxHealth;
	if (level >= 5)
		this->proficiencyBonus = 3;
	if (level >= 9)
		this->proficiencyBonus = 4;
	if (level >= 13)
		this->proficiencyBonus = 5;
	if (level >= 17)
		this->proficiencyBonus = 6;
}