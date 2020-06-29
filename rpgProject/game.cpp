#include "game.h"

#include <ctime>
#include <iostream>

#include "game_state.h"
#include "constants.h"
#include "entity.h"
#include "entity_manager.h"

void game::initialize()
{
	srand(static_cast<unsigned>(time(nullptr))); // seed the dice rolls
}

void game::cleanup()
{
	// cleanup all the states_
	while (!states_.empty())
	{
		states_.back()->cleanup();
		states_.pop_back();
	}
}

void game::change_state(game_state* state)
{
	// cleanup the current state
	if (!states_.empty())
	{
		states_.back()->cleanup();
		states_.pop_back();
	}

	// store and init the new state
	states_.push_back(state);
	states_.back()->init();
}

void game::push_state(game_state* state)
{
	// pause current state
	if (!states_.empty())
	{
		states_.back()->pause();
	}

	// store and init the new state
	states_.push_back(state);
	states_.back()->init();
}

void game::pop_state()
{
	// cleanup the current state
	if (!states_.empty())
	{
		states_.back()->cleanup();
		states_.pop_back();
	}

	// resume previous state
	if (!states_.empty())
	{
		states_.back()->resume();
	}
}

void game::handle_events()
{
	// let the state handle events
	states_.back()->handle_events(this);
}

void game::update()
{
	entity_manager::instance()->update();
	
	states_.back()->update(this);
	
}

void game::render()
{
	if (entity_manager::instance()->has_no_entities())
		return;

	entity_manager::instance()->render();
	
	states_.back()->render(this);
}

void game::handle_camera_movement() const
{
}

void game::load_files()
{
	player = entity_manager::instance()->get_entity_by_name("player");
}
