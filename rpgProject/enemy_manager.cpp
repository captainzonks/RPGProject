#include "EnemyManager.h"

EnemyManager::~EnemyManager()
{
	this->CleanUp();
}

Actor* EnemyManager::CreateEnemy(int playerItemLevel)
{
	int random{ rand() % 1 + 1 };

	Actor* new_enemy{ nullptr };

	switch (random)
	{
	case 1:
		new_enemy = new Fighter(identifier);
		GetUpgrades(playerItemLevel, *new_enemy);
		identifier++;
		break;
	default:
		break;
	}

	return new_enemy;
}

void EnemyManager::GetUpgrades(int playerItemLevel, Actor& enemy)
{
	int random{ (rand() % 2) };
	// obtain new gear
	if (playerItemLevel > 1 && static_cast<int>(enemies.size()) < (playerItemLevel + 1))
	{
		// armor
		if (random == 1)
		{
			std::unique_ptr<Helmet> helmet = std::make_unique<Helmet>();
			enemy.EquipHelmet(std::move(helmet));
		}
		random = (rand() % 3);
		if (random == 1)
		{
			std::unique_ptr<Chest> chest = std::make_unique<Chest>();
			enemy.EquipChest(std::move(chest));
		}
		random = (rand() % 2);
		if (random == 1)
		{
			std::unique_ptr<Legs> legs = std::make_unique<Legs>();
			enemy.EquipLegs(std::move(legs));
		}
		random = (rand() % 3);
		if (random == 1)
		{
			std::unique_ptr<Hands> hands = std::make_unique<Hands>();
			enemy.EquipHands(std::move(hands));
		}
		random = (rand() % 2);
		if (random == 1)
		{
			std::unique_ptr<Boots> boots = std::make_unique<Boots>();
			enemy.EquipBoots(std::move(boots));
		}

		// sword/duel-wield and/or shield
		random = (rand() % 2);
		if (random == 1 && enemy.GetFightingStyle() != FIGHTING_STYLE::ARCHERY)
		{
			std::unique_ptr<Sword> swordL = std::make_unique<Sword>();
			enemy.EquipWeaponL(std::move(swordL));
			random = (rand() % 2);
			if (enemy.GetFightingStyle() == FIGHTING_STYLE::DUELING)
			{
				std::unique_ptr<Sword> swordR = std::make_unique<Sword>();
				enemy.EquipWeaponL(std::move(swordR));
			}
			else if (random == 0)
			{
				std::unique_ptr<Shield> shield = std::make_unique<Shield>();
				enemy.EquipShield(std::move(shield));
			}
		}
		else if (random == 0)
		{
			std::unique_ptr<ShortBow> bow = std::make_unique<ShortBow>();
			enemy.EquipRanged(std::move(bow));
		}
	}

	// upgrade gear
	if (playerItemLevel > 2 && static_cast<int>(enemies.size()) < (playerItemLevel + 3))
	{
		// upgrade armor
		if (enemy.myUpgrades.HelmetEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.helmet->UpgradeArmor();
				}
		}
		if (enemy.myUpgrades.ChestEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.chest->UpgradeArmor();
				}
		}
		if (enemy.myUpgrades.LegsEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.legs->UpgradeArmor();
				}
		}
		if (enemy.myUpgrades.HandsEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.hands->UpgradeArmor();
				}
		}
		if (enemy.myUpgrades.BootsEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.boots->UpgradeArmor();
				}
		}

		// upgrade weapons and shield
		if (enemy.myUpgrades.WeaponLEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.weaponL->UpgradeWeapon();
				}
		}
		if (enemy.myUpgrades.ShieldEquipped())
		{
			random = (rand() % 2);
			if (random == 1)
				for (int i{}; i < playerItemLevel; i++)
				{
					random = (rand() % 3);
					if (random == 1)
						enemy.myUpgrades.shield->UpgradeArmor();
				}
		}
	}
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
			enemy->Display();
			enemy->myUpgrades.DisplayUpgrades();
		}
	}
}

unsigned int EnemyManager::GetTotalEnemies()
{
	unsigned int total{ enemies.size() };
	return total;
}

std::vector<Actor*> EnemyManager::GetEnemies()
{
	return enemies;
}

Actor* EnemyManager::GetEnemy(int identifier)
{
	return enemies.at(identifier - 1);
}

int EnemyManager::GetIdentifier()
{
	return identifier;
}

/*
Checks for dead enemies in the vector and removes and deletes their pointer/object
*/
void EnemyManager::CleanUpDead()
{
	for (size_t i{}; i < enemies.size(); ++i)
	{
		if (!enemies.at(i)->IsAlive())
		{
			Actor* temp_ptr = enemies.at(i);
			enemies.erase(enemies.begin() + i);
			delete temp_ptr;
			if (identifier == 1)
				identifier = 1;
			else
				identifier--;
		}
	}
}

/*
Deletes all actor pointers in the enemies vector
*/
void EnemyManager::CleanUp()
{
	if (enemies.size() != 0)
	{
		for (auto enemy : enemies)
		{
			delete enemy;
		}
	}
	enemies.clear();
	identifier = 1;
}
