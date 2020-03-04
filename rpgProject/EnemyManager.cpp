#include "EnemyManager.h"

Actor* EnemyManager::CreateEnemy()
{
	int random{ rand() % 4 + 1 };

	Actor* new_enemy{ nullptr };

	switch (random)
	{
	case 1:
		new_enemy = new Human(identifier);
		identifier++;
		break;
	case 2:
		new_enemy = new Dwarf(identifier);
		identifier++;
		break;
	case 3:
		new_enemy = new Elf(identifier);
		identifier++;
		break;
	case 4:
		new_enemy = new Halfling(identifier);
		identifier++;
		break;
	default:
		break;
	}

	return new_enemy;
}

void EnemyManager::AddEnemy(Actor* enemy)
{
	enemies.push_back(enemy);
}

void EnemyManager::DisplayAllEnemies()
{
	if (enemies.size() == 0)
	{
		std::cout << "\nThere are no enemies!" << endl;
	}
	else
	{
		for (auto& enemy : enemies)
		{
			enemy->display();
		}
	}
}

Actor* EnemyManager::GetEnemy(int identifier)
{
	return enemies.at(identifier);
}

int EnemyManager::GetIdentifier()
{
	return identifier;
}

void EnemyManager::CheckForDead()
{
	for (size_t i{}; i < enemies.size(); ++i)
	{
		if (enemies.at(i)->livingOrDead())
		{
			return;
		}
		else
		{
			std::cout << enemies.at(i)->getName() << " died!" << std::endl;
			delete enemies.at(i);
			enemies.erase(enemies.begin() + i);
		}
	}
}

void EnemyManager::CleanUp()
{
	for (auto& enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
	identifier = 0;
}
