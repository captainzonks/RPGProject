#include "fighter_features.h"
#include "helper_functions.h"

#include <iostream>

void fighter_features::pick_fighting_style()
{
	const std::vector<std::string> pick_this{ "Pick this Fighting Style", "Choose a different Fighting Style" };

	std::cout << "\nWhat Fighting Style are you?" << std::endl;

	const std::vector<std::string> fighting_styles{ "Archery", "Defense", "Dueling", "Great Weapon Fighting", "Protection", "Two Weapon Fighting" };
	print_menu("Fighting Styles", fighting_styles);
	auto choice = menu_choice(fighting_styles);

	if (choice == 1)
	{
		const std::vector<std::string> archery_menu{ "Learn more about Archery", "Choose this Fighting Style", "Go Back" };
		print_menu("Archery", archery_menu);
		choice = menu_choice(archery_menu);

		if (choice == 1)
		{
			print_archery_def();

			print_menu("", pick_this);
			choice = menu_choice(pick_this);

			if (choice == 1)
				fighting_style_ = fighting_style::archery;
			else
				pick_fighting_style();
		}
		if (choice == 2)
			fighting_style_ = fighting_style::archery;
		if (choice == 3)
			pick_fighting_style();
	}
	else if (choice == 2)
	{
		const std::vector<std::string> defenseMenu{ "Learn more about Defense", "Choose this Fighting Style", "Go Back" };
		print_menu("Defense", defenseMenu);
		choice = menu_choice(defenseMenu);

		if (choice == 1)
		{
			print_defense_def();

			print_menu("", pick_this);
			choice = menu_choice(pick_this);

			if (choice == 1)
				fighting_style_ = fighting_style::defense;
			else
				pick_fighting_style();
		}
		if (choice == 2)
			fighting_style_ = fighting_style::defense;
		if (choice == 3)
			pick_fighting_style();
	}
	else if (choice == 3)
	{
		const std::vector<std::string> duelingMenu{ "Learn more about Dueling", "Choose this Fighting Style", "Go Back" };
		print_menu("Dueling", duelingMenu);
		choice = menu_choice(duelingMenu);

		if (choice == 1)
		{
			print_dueling_def();

			print_menu("", pick_this);
			choice = menu_choice(pick_this);

			if (choice == 1)
				fighting_style_ = fighting_style::dueling;
			else
				pick_fighting_style();
		}
		if (choice == 2)
			fighting_style_ = fighting_style::dueling;
		if (choice == 3)
			pick_fighting_style();
	}
	else if (choice == 4)
	{
		const std::vector<std::string> gwfMenu{ "Learn more about Great Weapon Fighting", "Choose this Fighting Style", "Go Back" };
		print_menu("Great Weapon Fighting", gwfMenu);
		choice = menu_choice(gwfMenu);

		if (choice == 1)
		{
			print_gwf_def();

			print_menu("", pick_this);
			choice = menu_choice(pick_this);

			if (choice == 1)
				fighting_style_ = fighting_style::great_weapon_fighting;
			else
				pick_fighting_style();
		}
		if (choice == 2)
			fighting_style_ = fighting_style::great_weapon_fighting;
		if (choice == 3)
			pick_fighting_style();
	}
	else if (choice == 5)
	{
		const std::vector<std::string> protectionMenu{ "Learn more about Protection", "Choose this Fighting Style", "Go Back" };
		print_menu("Protection", protectionMenu);
		choice = menu_choice(protectionMenu);

		if (choice == 1)
		{
			print_protection_def();

			print_menu("", pick_this);
			choice = menu_choice(pick_this);

			if (choice == 1)
				fighting_style_ = fighting_style::protection;
			else
				pick_fighting_style();
		}
		if (choice == 2)
			fighting_style_ = fighting_style::protection;
		if (choice == 3)
			pick_fighting_style();
	}
	else if (choice == 6)
	{
		const std::vector<std::string> twfMenu{ "Learn more about Two-Weapon Fighting", "Choose this Fighting Style", "Go Back" };
		print_menu("Two-Weapon Fighting", twfMenu);
		choice = menu_choice(twfMenu);

		if (choice == 1)
		{
			print_twf_def();

			print_menu("", pick_this);
			choice = menu_choice(pick_this);

			if (choice == 1)
				fighting_style_ = fighting_style::two_weapon_fighting;
			else
				pick_fighting_style();
		}
		if (choice == 2)
			fighting_style_ = fighting_style::two_weapon_fighting;
		if (choice == 3)
			pick_fighting_style();
	}
}

void fighter_features::set_fighting_style(fighting_style const fighting_style)
{
	fighting_style_ = fighting_style;
}

void fighter_features::display_class_information()
{
	std::cout << "\n\n******fighter lvl " << get_level() << "******" << std::endl;
	if (get_fighting_style() == fighting_style::archery)
	{
		print_archery_def();
	}
	if (get_fighting_style() == fighting_style::defense)
	{
		print_defense_def();
	}
	if (get_fighting_style() == fighting_style::dueling)
	{
		print_dueling_def();
	}
	if (get_fighting_style() == fighting_style::great_weapon_fighting)
	{
		print_gwf_def();
	}
	if (get_fighting_style() == fighting_style::protection)
	{
		print_protection_def();
	}
	if (get_fighting_style() == fighting_style::two_weapon_fighting)
	{
		print_twf_def();
	}
}

void fighter_features::print_twf_def()
{
	std::cout << "\n==Two-Weapon Fighting==" << std::endl;
	std::cout << "When you engage in two-weapon fighting," << std::endl;
	std::cout << "you can add your ability modifier to" << std::endl;
	std::cout << "the damage of the second attack." << std::endl;
	std::cout << "-----------" << std::endl;
}

void fighter_features::print_protection_def()
{
	std::cout << "\n==Protection==" << std::endl;
	std::cout << "When a creature you can see attacks a" << std::endl;
	std::cout << "target other than you that is within" << std::endl;
	std::cout << "5 feet of you, you can use your reaction" << std::endl;
	std::cout << "to impose disadvantage on the attack roll." << std::endl;
	std::cout << "You must be wielding a shield." << std::endl;
	std::cout << "-----------" << std::endl;
}

void fighter_features::print_gwf_def()
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

void fighter_features::print_dueling_def()
{
	std::cout << "\n==Dueling==" << std::endl;
	std::cout << "When you are wielding a melee" << std::endl;
	std::cout << "weapon in one hand and no other" << std::endl;
	std::cout << "weapons, you gain a +2 bonus to" << std::endl;
	std::cout << "damage rolls with that weapon." << std::endl;
	std::cout << "-----------" << std::endl;
}

void fighter_features::print_defense_def()
{
	std::cout << "\n==Defense==" << std::endl;
	std::cout << "While you are wearing armor," << std::endl;
	std::cout << "you gain a +1 bonus to AC." << std::endl;
	std::cout << "-----------" << std::endl;
}

void fighter_features::print_archery_def()
{
	std::cout << "\n==Archery==" << std::endl;
	std::cout << "You gain a +2 bonus to attack rolls" << std::endl;
	std::cout << "you make with ranged weapons." << std::endl;
	std::cout << "-----------" << std::endl;
}
