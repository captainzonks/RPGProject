#pragma once

#include <Windows.h>
#include <iostream>
#include <memory>
#include <time.h>
#include <stack>

#include "GameState.h"
#include "EnemyManager.h"
#include "Actor.h"
#include "Human.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Narrator.h"
#include "Encounter.h"
#include "Item.h"

class Game
{
public:
	Actor* player;

	void Initialize();
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	void GameLoop();

	void GetInput(Actor& player);


	void RandomEncounter(Actor& player);
	void StartEncounter(Actor& player);

	bool IsRunning();
	void Quit() { isRunning = false; };

	Narrator narrator;
	EnemyManager manager;
	
private:
	bool isRunning{ false };
	std::vector<GameState*> states;
};

