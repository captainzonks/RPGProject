#include "character_builder.h"

#include <memory>

#include "character.h"
#include "attributes.h"
#include "combat_class.h"
#include "currency.h"
#include "helper_functions.h"

character_builder character_builder::character_builder_instance_;

void character_builder::build_attributes()
{
	std::cout << "\nWhat race are you?" << std::endl;
	const std::vector<std::string> race_options{ "Human", "Dwarf", "Elf", "Halfling" };
	print_menu("Races", race_options);
	auto race_choice { menu_choice(race_options) };

	std::cout << "\nWhat's your name?" << std::endl;
	std::string name;
	std::cin >> name;
	
	auto strength {roll_dice_ignore_lowest(4, 6)};
	auto dexterity {roll_dice_ignore_lowest(4, 6)};
	auto constitution {roll_dice_ignore_lowest(4, 6)};
	auto intelligence {roll_dice_ignore_lowest(4, 6)};
	auto wisdom {roll_dice_ignore_lowest(4, 6)};
	auto charisma {roll_dice_ignore_lowest(4, 6)};

	if(race_choice == 1) // human
	{
		strength++;
		dexterity++;
		constitution++;
		intelligence++;
		wisdom++;
		charisma++;
	}
	else if(race_choice == 2) // dwarf
	{
		strength += 2;
		constitution += 2;
	}
	else if( race_choice == 3) // elf
	{
		dexterity += 2;
		intelligence++;
		wisdom++;
		charisma++;
	}
	else // halfling
	{
		constitution++;
		charisma++;
	}

	built_attributes_ = new attributes("Player", name, static_cast<::race_options>(race_choice), strength,
	                                          dexterity, constitution,
	                                          intelligence, wisdom, charisma);
}

void character_builder::build_currency()
{
	built_currency_ = new currency();
}

void character_builder::build_combat_class()
{
	std::cout << "\nWhat class are you?" << std::endl;
	const std::vector<std::string> class_options{ "Fighter", "Wizard", "Rogue" };
	print_menu("Classes", class_options);
	auto choice { menu_choice(class_options) };

	built_combat_class_ = new combat_class(static_cast<combat_class_enum>(choice));
}

std::shared_ptr<character> character_builder::build_character()
{
	build_attributes();
	build_currency();
	build_combat_class();

	result_ = std::make_shared<character>(built_attributes_, built_currency_, built_combat_class_);
	
	return result_;
}
