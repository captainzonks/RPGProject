#pragma once

#include <Windows.h>
#include <iostream>
#include <memory>
#include <time.h>

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
	void Initialize();

	void GameLoop();

	void GetInput(std::shared_ptr<Actor> player);
	void Update(std::shared_ptr<Actor> player);

	void RandomEncounter(std::shared_ptr<Actor> player);
	void StartEncounter(std::shared_ptr<Actor> player);

	bool IsRunning();

	Narrator narrator;
	EnemyManager manager;
	
private:
	bool isRunning{ false };
};

