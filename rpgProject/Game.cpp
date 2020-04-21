#include "game.h"
#include "game_state.h"
#include "constants.h"

#include <ctime>
#include <iostream>

#include "character_creator_state.h"

void game::initialize()
{
	std::cout << welcome_message + " " + game_version << std::endl;
	std::cout << "------------------------------------" << std::endl;
	srand(static_cast<unsigned>(time(nullptr))); // seed the dice rolls
	running_ = true;
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
	if (is_running())
	{
		states_.back()->handle_events(this);
	}
}

void game::update()
{
	// let the state update the game
	if (is_running())
	{
		states_.back()->update(this);
	}
}

void game::draw()
{
	// let the state draw the screen
	if (is_running())
	{
		states_.back()->draw(this);
	}
}