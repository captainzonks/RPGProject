#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "asset_manager.h"
#include "character_manager.h"
#include "world_map.h"

class character;
class game_state;

class game
{
public:
	game() = default;
	~game() = default;
	
	std::shared_ptr<character> player;
	//character_manager manager { *character_manager::instance() };
	//asset_manager asset_manager { *asset_manager::instance() };
	//world_map world { *world_map::instance() };

	inline static SDL_Renderer* renderer { nullptr };
	inline static SDL_Event event;
	inline static SDL_Rect camera;

	void initialize(int width, int height);
	void cleanup();

	void change_state(game_state* state);
	void push_state(game_state* state);
	void pop_state();

	void handle_events();
	void update();
	void draw();

	void handle_camera_movement() const;

	[[nodiscard]] bool is_running() const { return running_; }
	void quit() { running_ = false; };

private:
	bool running_{ false };
	SDL_Window* window_ { nullptr };
	std::vector<game_state*> states_;

	int ticks_last_frame_ {};
};

#endif