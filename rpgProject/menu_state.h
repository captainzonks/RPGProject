#pragma once

#include <string>

#include "game_state.h"

class menu_state final
	:	public game_state
{
public:
	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handle_events(game* game) override;
	void update(game* game) override;
	void draw(game* game) override;

	static menu_state* instance()
	{
		return &menu_state_;
	}

protected:
	menu_state() = default;
	unsigned choice_{};
	static menu_state menu_state_;
	std::vector<std::string> options_{ "Display Player Stats", "Display Class",
		"Display Money", "Display Inventory", "Exit game" };
	const std::string name_{ "Main Menu" };
};

