#pragma once

#include "game_state.h"

class menu_state :
	public game_state
{
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void handle_events(game* game);
	void update(game* game);
	void draw(game* game);

	static menu_state* instance()
	{
		return &menu_state_;
	}

protected:
	menu_state() = default;
	int choice_{};
	static menu_state menu_state_;
	std::vector<std::string> options_{ "Display Player", "Display Class Information",
		"Display Money", "Display Upgrades", "Display Potions", "Buy Something",
		"Use A Potion", "Display Enemies", "Attack", "Add Enemy", "Exit game" };
	const std::string name_{ "Main Menu" };
};

