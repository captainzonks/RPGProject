#pragma once
#define NOMINMAX
#include "Game.h"

class GameState
{
public:
	// setup and destroy the state
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	// used when temporarily transitioning to another state
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	// the three important actions within a game loop
	// (handled by the top state in the stack)
	virtual void HandleEvents(Game* game) = 0;
	virtual void Update(Game* game) = 0;
	virtual void Draw(Game* game) = 0;

	void ChangeState(Game* game, GameState* state)
	{
		game->ChangeState(state);
	}

protected:
	GameState() {}
};

