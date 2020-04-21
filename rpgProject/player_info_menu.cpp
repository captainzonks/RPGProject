#include "player_info_menu.h"
#include "character.h"
#include "helper_functions.h"

player_info_menu player_info_menu::player_info_menu_state_;

void player_info_menu::init()
{
}

void player_info_menu::cleanup()
{
}

void player_info_menu::pause()
{
}

void player_info_menu::resume()
{
}

void player_info_menu::handle_events(game* game)
{
	if (choice_ != 0)
	{
		switch (choice_)
		{
		case 1:
			game->player->display();
			break;
		case 2:
			game->player->access_inventory().display_inventory();
			game->player->access_inventory().display_equipped();
			break;
		case 3:
			game->player->access_currency().display_money();
			break;
		case 4:
			game->pop_state();
			break;
		default:
			break;
		}
	}
}

void player_info_menu::update(game* game)
{
}

void player_info_menu::draw(game* game)
{
	print_menu(this->name_, options_);

	choice_ = menu_choice(options_);
}
