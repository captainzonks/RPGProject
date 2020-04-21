#include "npc_info_menu.h"
#include "character_builder.h"
#include "helper_functions.h"

#include <iostream>

npc_info_menu npc_info_menu::npc_info_menu_state_;

void npc_info_menu::init()
{
}

void npc_info_menu::cleanup()
{
}

void npc_info_menu::pause()
{
}

void npc_info_menu::resume()
{
}

void npc_info_menu::handle_events(game* game)
{
	if (choice_ != 0)
	{
		switch (choice_)
		{
		case 1:
			game->manager.add_character(character_builder::instance()->build_character());
			std::cout << "\nNPC created" << std::endl;
			break;
		case 2:
			game->manager.display_all_npcs();
			break;
		case 3:
			std::cout << "\nTotal NPCs: " << game->manager.total_npcs() << std::endl;
			break;
		case 4:
			game->pop_state();
			break;
		default:
			break;
		}
	}
}

void npc_info_menu::update(game* game)
{
}

void npc_info_menu::draw(game* game)
{
	print_menu(this->name_, options_);

	choice_ = menu_choice(options_);
}
