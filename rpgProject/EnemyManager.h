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
	std::shared_ptr<Actor> CreateEnemy();
	void AddEnemy(std::shared_ptr<Actor> enemy);
	void DisplayAllEnemies();
	unsigned int GetTotalEnemies();
	std::vector<std::shared_ptr<Actor>> GetEnemies();
	std::shared_ptr<Actor> GetEnemy(int identifier);

	int GetIdentifier();

	void CheckForDead();
	void CleanUp();

private:
	std::vector<std::shared_ptr<Actor>> enemies;
	int identifier{};
};

