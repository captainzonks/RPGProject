#include "player_info_menu.h"
#include "entity.h"
#include "currency_component.h"
#include "helper_functions.h"
#include "inventory_component.h"

player_info_menu player_info_menu::player_info_menu_state_;

void player_info_menu::init(game* game)
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
			game->player->get_component<inventory_component>()->display_inventory();
			game->player->get_component<inventory_component>()->display_equipped();
			break;
		case 3:
			game->player->get_component<currency_component>()->display_money();
			break;
		case 4:
			game->player->list_all_components();
			break;
		case 5:
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
