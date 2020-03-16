#pragma once

#include "Fighter.h"
//#include "Human.h"
//#include "Dwarf.h"
//#include "Elf.h"
//#include "Halfling.h"
#include "Upgrades.h"

#include <vector>

class EnemyManager
{
public:
	Actor* CreateEnemy(int playerItemLevel);
	void GetUpgrades(int playerItemLevel, Actor& enemy);
	void AddEnemy(Actor* enemy);
	void DisplayAllEnemies();
	unsigned int GetTotalEnemies();
	std::vector<Actor*> GetEnemies();
	Actor* GetEnemy(int identifier);

	int GetIdentifier();

	void CheckForDead();
	void CleanUpDead();
	void CleanUp();

private:
	std::vector<Actor*> enemies;
	int identifier{};
};

