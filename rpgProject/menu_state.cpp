#include "menu_state.h"
#include "character.h"
#include "helper_functions.h"

#include <iostream>

menu_state menu_state::menu_state_;

void menu_state::init()
{
}

void menu_state::cleanup()
{
}

void menu_state::pause()
{
}

void menu_state::resume()
{
}

void menu_state::handle_events(game* game)
{
	if (choice_ != 0)
	{
		switch (choice_)
		{
		case 1:
			game->player->display();
			break;
		case 2:
			game->player->access_combat_class().display_class();
			break;
		case 3:
			game->player->access_currency().display_money();
			break;
		case 4:
			game->player->access_inventory().display_inventory();
			break;
		case 5:
			game->quit();
			break;
		default:
			break;
		}
	}
}

void menu_state::update(game* game)
{
	game->player->update();
}

void menu_state::draw(game* game)
{
	print_menu(this->name_, options_);

	choice_ = menu_choice(options_);
}
