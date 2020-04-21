#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "character_manager.h"

class character;
class game_state;

class game
{
public:
	std::shared_ptr<character> player;
	character_manager manager { *character_manager::instance() };

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
};

#endif