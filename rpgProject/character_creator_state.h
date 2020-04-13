#pragma once

#include "game_state.h"

class character_creator_state final:
	public game_state
{
public:
	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handle_events(game* game) override;
	void update(game* game) override;
	void draw(game* game) override;

	static character_creator_state* instance()
	{
		return &character_creator_state_;
	}

protected:
	character_creator_state() = default;
	int race_choice_{};
	std::string race_{};
	std::string char_name_{};
	int class_choice_{};
	static character_creator_state character_creator_state_;
	std::vector<std::string> race_options_{ "Human", "Dwarf", "Elf", "Halfling" };
	std::vector<std::string> class_options_{ "Fighter" };
	const std::string races_{ "Races" };
	const std::string classes_{ "Classes" };
};

