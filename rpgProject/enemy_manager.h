#pragma once

#include "Fighter.h"
//#include "Human.h"
//#include "Dwarf.h"
//#include "Elf.h"
//#include "Halfling.h"
#include "upgrades.h"

#include <vector>

class EnemyManager
{
public:
	~EnemyManager();
	actor* CreateEnemy(int playerItemLevel);
	void GetUpgrades(int playerItemLevel, actor& enemy);
	void AddEnemy(actor* enemy);
	void DisplayAllEnemies();
	unsigned int GetTotalEnemies();
	std::vector<actor*> GetEnemies();
	actor* GetEnemy(int identifier);

	int GetIdentifier();

	void CleanUpDead();
	void CleanUp();

private:
	std::vector<actor*> enemies;
	int identifier{ 1 };
};
