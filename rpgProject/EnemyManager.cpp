#include "EnemyManager.h"

std::shared_ptr<Actor> EnemyManager::CreateEnemy()
{
	int random{ rand() % 4 + 1 };

	std::shared_ptr<Actor> new_enemy{ nullptr };

	switch (random)
	{
	case 1:
		new_enemy = std::make_shared<Human>(identifier);
		identifier++;
		break;
	case 2:
		new_enemy = std::make_shared<Dwarf>(identifier);
		identifier++;
		break;
	case 3:
		new_enemy = std::make_shared<Elf>(identifier);
		identifier++;
		break;
	case 4:
		new_enemy = std::make_shared<Halfling>(identifier);
		identifier++;
		break;
	default:
		break;
	}

	return new_enemy;
}

void EnemyManager::AddEnemy(std::shared_ptr<Actor> enemy)
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
			enemy->Display();
		}
	}
}

unsigned int EnemyManager::GetTotalEnemies()
{
	unsigned int total{ enemies.size() };
	return total;
}

std::vector<std::shared_ptr<Actor>> EnemyManager::GetEnemies()
{
	return enemies;
}

std::shared_ptr<Actor> EnemyManager::GetEnemy(int identifier)
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
		if (!enemies.at(i)->LivingOrDead())
		{
			std::cout << "\n" << enemies.at(i)->GetName() << " died!" << std::endl;
			enemies.erase(enemies.begin() + i);
		}
	}
}

void EnemyManager::CleanUp()
{
	enemies.clear();
	identifier = 0;
}
