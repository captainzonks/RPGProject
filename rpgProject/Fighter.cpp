#include "Fighter.h"

Fighter::Fighter()
{
	this->hitDice = 10;
	this->hitDiceQuantity = 1;
}

Fighter::~Fighter()
{
	std::cout << "Fighter destructor called" << std::endl; // debug
}

void Fighter::SetFightingStyle()
{
	std::cout << "What Fighting Style are you?" << std::endl;

	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(6);
	std::unique_ptr<vector<string>> tempDecisions = 
		std::make_unique<vector<string>>(std::initializer_list<string>(
			{ "Archery", "Defense", "Dueling", "Great Weapon Fighting", "Protection", "Two Weapon Fighting" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	if (choice == 1)
	{
		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<string>> tempDecisions =
			std::make_unique<vector<string>>(std::initializer_list<string>(
				{ "Learn more about Archery", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "==Archery==" << std::endl;
			std::cout << "You gain a +2 bonus to attack rolls" << std::endl;
			std::cout << "you make with ranged weapons." << std::endl;
			std::cout << "-----------" << std::endl;
			
			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<string>> tempDecisions =
				std::make_unique<vector<string>>(std::initializer_list<string>(
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
		std::unique_ptr<vector<string>> tempDecisions =
			std::make_unique<vector<string>>(std::initializer_list<string>(
				{ "Learn more about Defense", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "==Defense==" << std::endl;
			std::cout << "While you are wearing armor," << std::endl;
			std::cout << "you gain a +1 bonus to AC." << std::endl;
			std::cout << "-----------" << std::endl;

			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<string>> tempDecisions =
				std::make_unique<vector<string>>(std::initializer_list<string>(
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
		std::unique_ptr<vector<string>> tempDecisions =
			std::make_unique<vector<string>>(std::initializer_list<string>(
				{ "Learn more about Dueling", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "==Dueling==" << std::endl;
			std::cout << "When you are wielding a melee" << std::endl;
			std::cout << "weapon in one hand and no other" << std::endl;
			std::cout << "weapons, you gain a +2 bonus to" << std::endl;
			std::cout << "damage rolls with that weapon." << std::endl;
			std::cout << "-----------" << std::endl;

			choice = 0;
			std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
			std::unique_ptr<int> const decisions = std::make_unique<int>(2);
			std::unique_ptr<vector<string>> tempDecisions =
				std::make_unique<vector<string>>(std::initializer_list<string>(
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
		std::unique_ptr<vector<string>> tempDecisions =
			std::make_unique<vector<string>>(std::initializer_list<string>(
				{ "Learn more about Great Weapon Fighting", "Choose this Fighting Style" }));
		choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

		if (choice == 1)
		{
			std::cout << "==Great Weapon Fighting==" << std::endl;
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
			std::unique_ptr<vector<string>> tempDecisions =
				std::make_unique<vector<string>>(std::initializer_list<string>(
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
	std::unique_ptr<vector<string>> tempDecisions =
		std::make_unique<vector<string>>(std::initializer_list<string>(
			{ "Learn more about Protection", "Choose this Fighting Style" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	if (choice == 1)
	{
		std::cout << "==Protection==" << std::endl;
		std::cout << "When a creature you can see attacks a" << std::endl;
		std::cout << "target other than you that is within" << std::endl;
		std::cout << "5 feet of you, you can use your reaction" << std::endl;
		std::cout << "to impose disadvantage on the attack roll." << std::endl;
		std::cout << "You must be wielding a shield." << std::endl;
		std::cout << "-----------" << std::endl;

		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<string>> tempDecisions =
			std::make_unique<vector<string>>(std::initializer_list<string>(
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
	std::unique_ptr<vector<string>> tempDecisions =
		std::make_unique<vector<string>>(std::initializer_list<string>(
			{ "Learn more about Two-Weapon Fighting", "Choose this Fighting Style" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	if (choice == 1)
	{
		std::cout << "==Two-Weapon Fighting==" << std::endl;
		std::cout << "When you engage in two-weapon fighting," << std::endl;
		std::cout << "you can add your ability modifier to" << std::endl;
		std::cout << "the damage of the second attack." << std::endl;
		std::cout << "-----------" << std::endl;

		choice = 0;
		std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
		std::unique_ptr<int> const decisions = std::make_unique<int>(2);
		std::unique_ptr<vector<string>> tempDecisions =
			std::make_unique<vector<string>>(std::initializer_list<string>(
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
