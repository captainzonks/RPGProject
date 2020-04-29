#include "game.h"
#include "game_state.h"
#include "constants.h"

#include <ctime>
#include <iostream>

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
	// wait until 16ms has ellapsed since the last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_last_frame_ + frame_target_time));

	// delta time is the difference in ticks from last frame converted to seconds
	auto delta_time = SDL_GetTicks() - static_cast<float>(ticks_last_frame_) / 1000.0f;

	// clamp delta time to a max value
	delta_time = delta_time > 0.05 ? 0.05f : delta_time;

	// sets the new ticks for the current frame to be used in the next pass
	ticks_last_frame_ = SDL_GetTicks();
	
	// let the state update the game
	manager.update(delta_time);
	
}

void game::draw()
{
	// let the state draw the screen
	if (is_running())
	{
		states_.back()->draw(this);
	}
}