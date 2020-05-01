#include "game.h"
#include "game_state.h"
#include "constants.h"

#include <ctime>
#include <iostream>

#include "entity.h"
#include "entity_manager.h"
#include "transform_component.h"

void game::initialize(const int width, const int height)
{
	srand(static_cast<unsigned>(time(nullptr))); // seed the dice rolls

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error initializing SDL." << std::endl;
		return;
	}

	if (TTF_Init() != 0)
	{
		std::cerr << "Error initializing SDL TTF." << std::endl;
		return;
	}

	window_ = SDL_CreateWindow(
		nullptr, 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_BORDERLESS
	);

	if (!window_)
	{
		std::cerr << "Error creating SDL window." << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window_, -1, 0);

	if (!renderer)
	{
		std::cerr << "Error creating SDL renderer." << std::endl;
		return;
	}
	
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

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window_);
	SDL_Quit();
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
	states_.back()->init(this);
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
	states_.back()->init(this);
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
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		running_ = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			running_ = false;
	default:
		break;
	}
	
	// let the state handle events
	states_.back()->handle_events(this);

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
	entity_manager::instance()->update(delta_time);

	handle_camera_movement();

	states_.back()->update(this);
	
}

void game::draw()
{
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	SDL_RenderClear(renderer);

	if (entity_manager::instance()->has_no_entities())
		return;
	
	states_.back()->draw(this);

	SDL_RenderPresent(renderer);
}

void game::handle_camera_movement() const
{
	if (player)
	{
		const auto player_transform = player->get_component<transform_component>();

		camera.x = static_cast<int>(player_transform->position.x) - (static_cast<int>(window_width) / 2);
		camera.y = static_cast<int>(player_transform->position.y) - (static_cast<int>(window_height) / 2);

		camera.x = camera.x < 0 ? 0 : camera.x;
		camera.y = camera.y < 0 ? 0 : camera.y;
		camera.x = camera.x > camera.w ? camera.w : camera.x;
		camera.y = camera.y > camera.h ? camera.h : camera.y;
	}
}
