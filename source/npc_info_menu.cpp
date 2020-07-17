#include "npc_info_menu.h"
#include "helper_functions.h"
#include "character_builder.h"
#include "entity_manager.h"

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

void npc_info_menu::handle_events(game *game)
{
    if (choice_ != 0)
    {
        switch (choice_)
        {
        case 1:
            entity_manager::instance()->add_entity(character_builder::instance()->build_character());
            break;
        case 2:
            entity_manager::instance()->display_entities();
            break;
        case 3:
            std::cout << entity_manager::instance()->get_entity_count() << std::endl;
            break;
        case 4:
            game->pop_state();
            break;
        default:
            break;
        }
    }
}

void npc_info_menu::update(game *game)
{
}

void npc_info_menu::render(game *game)
{
    print_menu(this->name_, options_);

    choice_ = menu_choice(options_);
}
