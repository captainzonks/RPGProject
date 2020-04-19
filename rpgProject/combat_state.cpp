//#include "CombatState.h"
//
//CombatState CombatState::m_CombatState;
//
//void CombatState::Init()
//{
//	firstRound = true;
//}
//
//void CombatState::Cleanup()
//{
//	manager->CleanUp();
//}
//
//void CombatState::Pause()
//{
//}
//
//void CombatState::Resume()
//{
//}
//
//void CombatState::HandleEvents(Game* game)
//{
//	if (choice != 0)
//	{
//		switch (choice)
//		{
//		case 1:
//			HandleCombat(game);
//			break;
//		case 2:
//			game->player->UsePotion();
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void CombatState::Update(Game* game)
//{
//	if (firstRound)
//	{
//		this->manager = &game->manager;
//		std::cout << "Roll for initiative!" << std::endl;
//		game->player->RollForInitiative();
//		initiativeOrder.push_back(game->player);
//		for (auto enemy : game->manager.GetEnemies())
//		{
//			enemy->RollForInitiative();
//			enemy->Update();
//			initiativeOrder.push_back(enemy);
//		}
//		SortInitiativeOrder();
//		DisplayIniatives();
//		firstRound = false;
//	}
//	else
//	{
//		if (game->manager.GetEnemies().size() == 0)
//		{
//			std::cout << "\nAll enemies have been defeated!" << std::endl;
//			game->player->ClearInitiative();
//			initiativeOrder.clear();
//			game->PopState();
//		}
//	}
//}
//
//void CombatState::Draw(Game* game)
//{
//	game->player->Display();
//	game->manager.DisplayAllEnemies();
//
//	PrintMenu(name, options);
//	choice = MenuChoice(options);
//}
//
//void CombatState::HandleCombat(Game* game)
//{
//	static int round{ 1 };
//	std::cout << "\n====ROUND " << round << "====" << std::endl;
//
//	for (auto attacker : initiativeOrder)
//	{
//		if (initiativeOrder.size() == 1)
//			break;
//
//		// pick a target
//		if (attacker->GetName() == game->player->GetName())
//		{
//			target = PickTarget(game);
//		}
//		else
//			target = game->player;
//
//		// make an attack
//		if (target->IsAlive() && game->player->IsAlive())
//			Attack::MakeAnAttack(*attacker, *target);
//
//		if (target->GetName() == game->player->GetName())
//		{
//			if (!game->player->IsAlive())
//			{
//				std::cout << "\nYou were killed by: " << std::endl;
//				attacker->Display();
//				std::cout << "\nGAME OVER" << std::endl;
//				initiativeOrder.clear();
//				game->Quit();
//				return;
//			}
//		}
//		else
//		{
//			for (auto enemy : manager->GetEnemies())
//			{
//				if (!enemy->IsAlive())
//				{
//					std::vector<Actor*>::iterator itr{ std::find(initiativeOrder.begin(), initiativeOrder.end(), target) };
//					initiativeOrder.erase(initiativeOrder.begin() + std::distance(initiativeOrder.begin(), itr));
//					manager->CleanUpDead();
//					if (initiativeOrder.size() == 1)
//						break;
//				}
//			}
//		}
//	}
//	std::cout << "\nRound " << round << " of combat has passed!" << std::endl; // debug
//	round++;
//	std::cout << "=================" << std::endl;
//}
//
//void CombatState::SortInitiativeOrder()
//{
//	Actor* temp{ nullptr };
//	for (size_t i{}; i < initiativeOrder.size(); ++i)
//	{
//		for (size_t j{ i + 1 }; j < initiativeOrder.size(); ++j)
//		{
//			if (initiativeOrder.at(i)->GetInitiative() < initiativeOrder.at(j)->GetInitiative())
//			{
//				temp = initiativeOrder.at(i);
//				initiativeOrder.at(i) = initiativeOrder.at(j);
//				initiativeOrder.at(j) = temp;
//			}
//		}
//	}
//}
//
///*
//Displays initiative for each actor in the
//initiative order, for debug purposes to
//make sure the orders are sorting properly
//*/
//void CombatState::DisplayIniatives()
//{
//	// debug display initiative order to check
//	for (auto actor : initiativeOrder)
//	{
//		std::cout << actor->GetName() << " Initiative: " << actor->GetInitiative() << std::endl;
//	}
//}
//
//Actor* CombatState::PickTarget(Game* game)
//{
//	std::cout << "\nPlease choose an enemy to attack:" << std::endl;
//	std::vector<std::string> enemyList{};
//	for (auto enemy : manager->GetEnemies())
//	{
//		enemyList.push_back(enemy->GetName());
//	}
//	PrintMenu("Enemies", enemyList);
//	int choice = MenuChoice(enemyList);
//
//	Actor* target = manager->GetEnemy(choice);
//
//	return target;
//}
