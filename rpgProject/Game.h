#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <ctime>
#include <string>
#include <vector>

#include "enemy_manager.h"
#include "actor.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "encounter.h"

class game_state;

class game
{
public:
	actor* player{ nullptr };

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

	enemy_manager manager;

private:
	bool running_{ false };
	std::vector<game_state*> states_;
};

#endif