#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "constants.h"
#include "world.h"

class entity;
class game_state;

class game
{
public:
	game() = default;
	~game() = default;

	std::shared_ptr<entity> player{nullptr};
	world the_world;

	void init();
	void cleanup();

	void change_state(game_state *state);
	void push_state(game_state *state);
	void pop_state();

	void handle_events();
	void update();
	void render();

	[[nodiscard]] bool is_running() const { return running_; }
	void quit() { running_ = false; };

private:
	bool running_{false};
	std::vector<game_state *> states_;

	int ticks_last_frame_{};
};

#endif