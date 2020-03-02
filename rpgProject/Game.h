#pragma once

#include <iostream>
#include <memory>
#include <time.h>

#include "Actor.h"
#include "Human.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Narrator.h"
#include "Item.h"

class Game
{
public:
	void Initialize();

	void GameLoop();

	void GetInput();
	void Update(Actor* player);

	bool IsRunning();

	Narrator narrator;
	
private:
	bool isRunning{ false };
};

