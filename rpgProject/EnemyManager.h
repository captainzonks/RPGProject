#pragma once

#include "Actor.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"

#include <vector>

class EnemyManager
{
public:
	Actor* CreateEnemy();
	void AddEnemy(Actor* enemy);
	void DisplayAllEnemies();
	Actor* GetEnemy(int identifier);

	int GetIdentifier();

	void CleanUp();

private:
	std::vector<Actor*> enemies;
	int identifier{};
};

