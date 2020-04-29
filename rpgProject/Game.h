#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "character_manager.h"
#include "world_map.h"

class character;
class game_state;

class game
{
public:
	std::shared_ptr<character> player;
	character_manager manager { *character_manager::instance() };
	world_map world { *world_map::instance() };

	void initialize();
	void cleanup();

	void change_state(game_state* state);
	void push_state(game_state* state);
	void pop_state();

	void handle_events();
	void update();
	void draw();

	[[nodiscard]] bool is_running() const { return running_; }
	void quit() { running_ = false; };

private:
	bool running_{ false };
	std::vector<game_state*> states_;

	int ticks_last_frame_ {};
};

#endif