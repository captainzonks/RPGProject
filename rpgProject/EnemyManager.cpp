#include "EnemyManager.h"

std::shared_ptr<Actor> EnemyManager::CreateEnemy(int playerItemLevel)
{
	int random{ rand() % 1 + 1 };

	std::shared_ptr<Actor> new_enemy{ nullptr };

	switch (random)
	{
	case 1:
		new_enemy = std::make_shared<Fighter>(identifier);
		new_enemy = GetUpgrades(playerItemLevel, new_enemy);
		identifier++;
		break;
	default:
		break;
	}

	return new_enemy;
}

std::shared_ptr<Actor> EnemyManager::GetUpgrades(int playerItemLevel, std::shared_ptr<Actor> enemy)
{
	int random{ (rand() % 2) };
	// obtain new gear
	if (playerItemLevel > 1 && static_cast<int>(enemies.size()) < (playerItemLevel + 1))
	{
		// armor
		if (random == 1)
		{
			std::unique_ptr<Helmet> helmet = std::make_unique<Helmet>();
			enemy->EquipHelmet(std::move(helmet));
		}
		random = (rand() % 3);
		if (random == 1)
		{
			std::unique_ptr<Chest> chest = std::make_unique<Chest>();
			enemy->EquipChest(std::move(chest));
		}
		random = (rand() % 2);
		if (random == 1)
		{
			std::unique_ptr<Legs> legs = std::make_unique<Legs>();
			enemy->EquipLegs(std::move(legs));
		}
		random = (rand() % 3);
		if (random == 1)
		{
			std::unique_ptr<Hands> hands = std::make_unique<Hands>();
			enemy->EquipHands(std::move(hands));
		}
		random = (rand() % 2);
		if (random == 1)
		{
			std::unique_ptr<Boots> boots = std::make_unique<Boots>();
			enemy->EquipBoots(std::move(boots));
		}

		// sword and shield
		random = (rand() % 2);
		if (random == 1)
		{
			std::unique_ptr<Sword> sword = std::make_unique<Sword>();
			enemy->EquipWeapon(std::move(sword));
		}
		random = (rand() % 2);
		if (random == 1)
		{
			std::unique_ptr<Shield> shield = std::make_unique<Shield>();
			enemy->EquipShield(std::move(shield));
		}
	}

	// upgrade gear
	if (playerItemLevel > 2 && static_cast<int>(enemies.size()) < (playerItemLevel + 3))
	{
		// upgrade armor
		if (enemy->myUpgrades.HelmetEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.helmet->UpgradeArmor();
				}
		}
		if (enemy->myUpgrades.ChestEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.chest->UpgradeArmor();
				}
		}
		if (enemy->myUpgrades.LegsEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.legs->UpgradeArmor();
				}
		}
		if (enemy->myUpgrades.HandsEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.hands->UpgradeArmor();
				}
		}
		if (enemy->myUpgrades.BootsEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.boots->UpgradeArmor();
				}
		}

		// upgrade weapons and shield
		if (enemy->myUpgrades.WeaponEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.weapon->UpgradeWeapon();
				}
		}
		if (enemy->myUpgrades.ShieldEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy->myUpgrades.shield->UpgradeArmor();
				}
		}
	}

	return enemy;
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
			identifier--;
		}
	}
}

void EnemyManager::CleanUp()
{
	enemies.clear();
	identifier = 0;
}
