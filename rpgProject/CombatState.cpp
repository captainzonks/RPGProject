#include "CombatState.h"

void CombatState::Init()
{
}

void CombatState::Cleanup()
{
}

void CombatState::Pause()
{
}

void CombatState::Resume()
{
}

void CombatState::HandleEvents(Game* game)
{
	if (choice != 0)
	{
		switch (choice)
		{
		case 1:
			HandleCombat(game);
			break;
		case 2:
			break;
		default:
			break;
		}
	}
}

void CombatState::Update(Game* game)
{
	if (firstRound)
	{
		std::cout << "Roll for initiative!" << std::endl;
		game->player->RollForInitiative();
		initiativeOrder.push_back(game->player);
		for (auto enemy : game->manager.GetEnemies())
		{
			enemy->RollForInitiative();
			initiativeOrder.push_back(enemy);
		}
		SortInitiativeOrder();
		DisplayIniatives();
	}
}

void CombatState::Draw(Game* game)
{
	game->player->Display();
	game->manager.DisplayAllEnemies();

	PrintMenu(name, options);
	choice = MenuChoice(options);
}

void CombatState::HandleCombat(Game* game)
{
	EnemyManager& manager = game->manager;
	
	static int round{ 1 };
	std::cout << "\n====ROUND " << round << "====" << std::endl;
	for (auto attacker : initiativeOrder)
	{
		Actor* target;
		if (attacker->GetName() == game->player->GetName())
		{
			target = PickTarget(game);
		}
		else
			target = game->player;


	}

}

void CombatState::SortInitiativeOrder()
{
	Actor* temp{ nullptr };
	for (size_t i{}; i < initiativeOrder.size(); ++i)
	{
		for (size_t j{ i + 1 }; j < initiativeOrder.size(); ++j)
		{
			if (initiativeOrder.at(i)->GetInitiative() < initiativeOrder.at(j)->GetInitiative())
			{
				temp = initiativeOrder.at(i);
				initiativeOrder.at(i) = initiativeOrder.at(j);
				initiativeOrder.at(j) = temp;
			}
		}
	}
}

/*
Displays initiative for each actor in the
initiative order, for debug purposes to
make sure the orders are sorting properly
*/
void CombatState::DisplayIniatives()
{
	// debug Display initiative order to check
	for (auto actor : initiativeOrder)
	{
		std::cout << actor->GetName() << " Initiative: " << actor->GetInitiative() << std::endl;
	}
}

Actor* CombatState::PickTarget(Game* game)
{
	std::cout << "\nPlease choose an enemy to attack:" << std::endl;
	std::vector<std::string> enemyList{};
	for (auto enemy : game->manager.GetEnemies())
	{
		enemyList.push_back(enemy->GetName());
	}
	PrintMenu("Enemies", enemyList);
	int choice = MenuChoice(enemyList);

	Actor* target = game->manager.GetEnemy(choice);
}
