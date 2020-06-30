#ifndef CHARACTER_CREATOR_STATE_H
#define CHARACTER_CREATOR_STATE_H

#include "game_state.h"

class character_creator_state final : public game_state
{
public:
	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handle_events(game *game) override;
	void update(game *game) override;
	void render(game *game) override;

	static character_creator_state *instance()
	{
		return &character_creator_state_;
	}

protected:
	character_creator_state() = default;
	static character_creator_state character_creator_state_;
};

#endif