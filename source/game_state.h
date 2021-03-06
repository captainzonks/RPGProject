#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "game.h"

class game_state
{
public:
	game_state(const game_state &other) = default;

	game_state(game_state &&other) noexcept
	{
	}

	game_state &operator=(const game_state &other)
	{
		if (this == &other)
			return *this;
		return *this;
	}

	game_state &operator=(game_state &&other) noexcept
	{
		if (this == &other)
			return *this;
		return *this;
	}

	virtual ~game_state() = default;

	// setup and destroy the state
	virtual void init() = 0;
	virtual void cleanup() = 0;

	// used when temporarily transitioning to another state
	virtual void pause() = 0;
	virtual void resume() = 0;

	// the three important actions within a game loop
	virtual void handle_events(game *game) = 0;
	virtual void update(game *game) = 0;
	virtual void render(game *game) = 0;

	static void change_state(game *game, game_state *state)
	{
		game->change_state(state);
	}

protected:
	game_state() = default;
};

#endif