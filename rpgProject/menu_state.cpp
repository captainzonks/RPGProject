#include "menu_state.h"
#include "helper_functions.h"
#include "npc_info_menu.h"
#include "player_info_menu.h"
#include "shop_menu_state.h"

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
			game->push_state(player_info_menu::instance());
			break;
		case 2:
			game->push_state(shop_menu_state::instance());
			break;
		case 3:
			game->push_state(npc_info_menu::instance());
			break;
		case 4:
			game->quit();
			break;
		default:
			break;
		}
	}
}

void menu_state::update(game* game)
{
}

void menu_state::draw(game* game)
{
	print_menu(this->name_, options_);

	choice_ = menu_choice(options_);
}
