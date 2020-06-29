#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "constants.h"

class entity;
class game_state;

class game
{
public:
	game() = default;
	~game() = default;
	
	std::shared_ptr<entity> player { nullptr };

	void initialize();
	void cleanup();

	void change_state(game_state* state);
	void push_state(game_state* state);
	void pop_state();

	void handle_events();
	void update();
	void render();

	void handle_camera_movement() const;
	void load_files();

	[[nodiscard]] bool is_running() const { return running_; }
	void quit() { running_ = false; };

private:
	bool running_{ false };
	std::vector<game_state*> states_;

	int ticks_last_frame_ {};
};

#endif