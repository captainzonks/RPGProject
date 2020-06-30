#ifndef MAP_MENU_STATE_H
#define MAP_MENU_STATE_H

#include <string>

#include "game_state.h"

class map_menu_state final
	: public game_state
{
public:
	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handle_events(game* game) override;
	void update(game* game) override;
	void render(game* game) override;

	static map_menu_state* instance()
	{
		return &map_menu_state_;
	}

	//location* make_new_location();

protected:
	map_menu_state() = default;
	unsigned choice_{};
	static map_menu_state map_menu_state_;
	std::vector<std::string> options_
	{
		"New Location",
		"Print Places",
		"Back"
	};
	const std::string name_{ "Map Menu" };
};

#endif
