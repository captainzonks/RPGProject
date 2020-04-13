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
	if (race_choice != 0)
	{
		switch (raceChoice)
		{
		case 1:
			race = "Human";
			break;
		case 2:
			race = "Dwarf";
			break;
		case 3:
			race = "Elf";
			break;
		case 4:
			race = "Halfling";
			break;
		default:
			break;
		}
	}

	if (classChoice != 0)
	{
		switch (classChoice)
		{
		case 1:
			game->player = new Fighter(charName, race);
			game->change_state(MainMenuState::Instance());
			break;
		default:
			break;
		}
	}
}

void character_creator_state::Update(game* game)
{

}

void character_creator_state::Draw(game* game)
{
	std::cout << "\nWhat race are you?" << std::endl;

	print_menu(races, raceOptions);

	raceChoice = menu_choice(raceOptions);

	std::cout << "\nWhat's your name? ";
	std::cin >> charName;

	std::cout << "\nWhat class are you?" << std::endl;

	print_menu(classes, classOptions);

	classChoice = menu_choice(classOptions);
}
