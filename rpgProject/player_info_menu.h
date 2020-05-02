#ifndef PLAYER_INFO_MENU_H
#define PLAYER_INFO_MENU_H

#include <string>

#include "game_state.h"
class player_info_menu final
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

	static player_info_menu* instance()
	{
		return &player_info_menu_state_;
	}
protected:
	player_info_menu() = default;
	unsigned choice_{};
	static player_info_menu player_info_menu_state_;
	std::vector<std::string> options_
	{
		"Player Stats",
		"Inventory",
		"Money",
		"List All Components",
		"Back"
	};
	const std::string name_{ "Player Info" };
};

#endif
