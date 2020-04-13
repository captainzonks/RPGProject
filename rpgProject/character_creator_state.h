#pragma once

#include "game_state.h"

class character_creator_state :
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

	static character_creator_state* instance()
	{
		return &m_character_creator_state_;
	}

protected:
	character_creator_state() {}
	int race_choice{};
	std::string race{};
	std::string char_name{};
	int class_choice{};
	static character_creator_state m_character_creator_state_;
	std::vector<std::string> race_options{ "Human", "Dwarf", "Elf", "Halfling" };
	std::vector<std::string> class_options{ "Fighter" };
	const std::string races{ "Races" };
	const std::string classes{ "Classes" };
};

