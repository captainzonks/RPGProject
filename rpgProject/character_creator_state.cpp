#include "character_creator_state.h"
#include "menu_state.h"

character_creator_state character_creator_state::m_character_creator_state_;

void character_creator_state::init()
{
	cout << "\nLet's create a character!" << endl;
}

void character_creator_state::cleanup()
{
}

void character_creator_state::pause()
{
}

void character_creator_state::resume()
{
}

void character_creator_state::handle_events(game* game)
{
	if (race_choice_ != 0)
	{
		switch (race_choice_)
		{
		case 1:
			race_ = "Human";
			break;
		case 2:
			race_ = "Dwarf";
			break;
		case 3:
			race_ = "Elf";
			break;
		case 4:
			race_ = "Halfling";
			break;
		default:
			break;
		}
	}

	if (class_choice_ != 0)
	{
		switch (class_choice_)
		{
		case 1:
			game->player = new Fighter(char_name_, race_);
			game->change_state(menu_state::instance());
			break;
		default:
			break;
		}
	}
}

void character_creator_state::update(game* game)
{

}

void character_creator_state::draw(game* game)
{
	std::cout << "\nWhat race_ are you?" << std::endl;

	print_menu(races_, race_options_);

	race_choice_ = menu_choice(race_options_);

	std::cout << "\nWhat's your name? ";
	std::cin >> char_name_;

	std::cout << "\nWhat class are you?" << std::endl;

	print_menu(classes_, class_options_);

	class_choice_ = menu_choice(class_options_);
}
