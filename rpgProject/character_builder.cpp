#include "character_builder.h"
#include "character.h"
#include "attributes.h"
#include "combat_class.h"
#include "currency.h"
#include "helper_functions.h"
#include "inventory.h"

void character_builder::build_attributes() const
{
	std::cout << "\nWhat race are you?" << std::endl;
	const std::vector<std::string> race_options{ "Human", "Dwarf", "Elf", "Halfling" };
	print_menu("Races", race_options);
	auto race_choice { menu_choice(race_options) };

	std::cout << "\nWhat's your name?" << std::endl;
	std::string name;
	std::cin >> name;
	
	const auto strength {roll_dice_ignore_lowest(4, 6)};
	const auto dexterity {roll_dice_ignore_lowest(4, 6)};
	const auto constitution {roll_dice_ignore_lowest(4, 6)};
	const auto intelligence {roll_dice_ignore_lowest(4, 6)};
	const auto wisdom {roll_dice_ignore_lowest(4, 6)};
	const auto charisma {roll_dice_ignore_lowest(4, 6)};
	result_->access_attributes() = { attributes("Player", name, static_cast<::race_options>(race_choice), strength, dexterity, constitution, intelligence, wisdom, charisma) };
}

void character_builder::build_inventory() const
{
	result_->access_inventory() = { inventory() };
}

void character_builder::build_currency() const
{
	result_->access_currency() = { currency() };
}

void character_builder::build_combat_class() const
{
	result_->access_combat_class() = { combat_class() };
}

std::shared_ptr<character> character_builder::build_character() const
{
	build_attributes();
	build_inventory();
	build_currency();
	build_combat_class();

	return result_;
}
