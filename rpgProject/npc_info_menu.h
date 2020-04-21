#ifndef NPC_INFO_MENU_H
#define NPC_INFO_MENU_H

#include <string>

#include "game_state.h"

class npc_info_menu final
	: public game_state
{
public:
	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handle_events(game* game) override;
	void update(game* game) override;
	void draw(game* game) override;

	static npc_info_menu* instance()
	{
		return &npc_info_menu_state_;
	}
protected:
	npc_info_menu() = default;
	unsigned choice_{};
	static npc_info_menu npc_info_menu_state_;
	std::vector<std::string> options_
	{
		"Spawn Random NPC",
		"NPC Stats",
		"Total NPCs",
		"Back"
	};
	const std::string name_{ "NPC Debug Menu" };
};

#endif
