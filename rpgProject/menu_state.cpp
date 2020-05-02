#include "menu_state.h"
#include "helper_functions.h"
#include "map_menu_state.h"
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
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
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

void menu_state::render(game* game)
{
	print_menu(this->name_, options_);

	choice_ = menu_choice(options_);
}
