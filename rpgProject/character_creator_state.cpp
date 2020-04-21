#include "character_creator_state.h"

#include <iostream>

#include "character_builder.h"
#include "menu_state.h"

character_creator_state character_creator_state::character_creator_state_;

void character_creator_state::init()
{
	std::cout << "\nLet's create a character!" << std::endl;
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
	game->player = character_builder::instance()->build_character();
}

void character_creator_state::update(game* game)
{
	if(game->player)
		game->change_state(menu_state::instance());
}

void character_creator_state::draw(game* game)
{
}
