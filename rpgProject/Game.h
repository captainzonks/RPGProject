#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "encounter.h"

class character;
class game_state;

class game
{
public:
	std::shared_ptr<character> player;

	void initialize();
	void cleanup();

	void change_state(game_state* state);
	void push_state(game_state* state);
	void pop_state();

	void handle_events();
	void update();
	void draw();

	bool is_running() const { return running_; }
	void quit() { running_ = false; };

private:
	bool running_{ false };
	std::vector<game_state*> states_;
};

#endif