#pragma once

#include "GameState.h"

#include <vector>
#include <stdio.h>

using std::vector;

class GameEngine
{
public:
	void Init();
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

private:
	// the stack of states
	vector<GameState*> states;

	bool m_running;
};

