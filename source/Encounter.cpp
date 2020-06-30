//#include "Encounter.h"
//
//Encounter::Encounter(EnemyManager& manager, Actor& player)
//	: manager(manager), player(&player)
//{
//	std::cout << "\nEncounter (manager, player) overloaded constructor called" << std::endl; // debug
//	BeginEncounter(manager, player);
//}
//
//Encounter::~Encounter()
//{
//	for (auto actor : initiativeOrder)
//	{
//		actor->ClearInitiative();
//	}
//	initiativeOrder.clear();
//	std::cout << "\nEncounter destructor called" << std::endl; // debug
//}
//
//void Encounter::SortInitiativeOrder()
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
//void Encounter::DisplayIniatives()
//{
//	// debug Display initiative order to check
//	for (auto actor : initiativeOrder)
//	{
//		std::cout << actor->GetName() << " Initiative: " << actor->GetInitiative() << std::endl;
//	}
//}
//
//void Encounter::BeginEncounter(EnemyManager& manager, Actor& player)
//{
//	std::cout << "Roll for initiative!" << std::endl;
//	player.RollForInitiative();
//	initiativeOrder.push_back(&player);
//	for (auto enemy : manager.GetEnemies())
//	{
//		enemy->RollForInitiative();
//		initiativeOrder.push_back(enemy);
//	}
//	SortInitiativeOrder();
//	DisplayIniatives();
//	static int round{ 1 };
//	int count{};
//	while (count != 1)
//	{
//		std::cout << "\n====ROUND " << round << "====" << std::endl;
//		for (auto attacker : initiativeOrder)
//		{
//			Actor* target{ RandomTargetPicker(*attacker) };
//			std::vector<Actor*>::iterator itr{ std::find(initiativeOrder.begin(), initiativeOrder.end(), target) };
//			if (EncounterHandler(*attacker, *target))
//			{
//				if (target->GetName() == player.GetName())
//				{
//					std::cout << "You Died!" << std::endl;
//					std::cout << "\nYou were killed by: " << std::endl;
//					attacker->Display();
//					initiativeOrder.clear();
//					manager.CleanUp();
//					break;
//				}
//				else
//				{
//					initiativeOrder.clear();
//					manager.CleanUp();
//					break;
//				}
//				initiativeOrder.erase(initiativeOrder.begin() + std::distance(initiativeOrder.begin(), itr));
//			}
//		}
//		std::cout << "\nRound " << round << " of combat has passed!" << std::endl; // debug
//		round++;
//		count++;
//		std::cout << "=================" << std::endl;
//	}
//}
//
///*
//Randomly chooses a target from the initiative order,
//but checks to see if the target is not the same
//as the attacker... this is a debug function,
//to be rewritten and redone later
//*/
//Actor* Encounter::RandomTargetPicker(Actor& attacker)
//{
//	Actor* target{ initiativeOrder.at(rand() % initiativeOrder.size()) };
//	if (target->GetName() == attacker.GetName())
//		return RandomTargetPicker(attacker);
//
//	return target;
//}
//
//// returns TRUE if defender dies, FALSE if defender still lives
//bool Encounter::EncounterHandler(Actor& attacker, Actor& defender)
//{
//	if (Attack::MakeAnAttack(attacker, defender))
//	{
//		if (!defender.IsAlive())
//		{
//			manager.CleanUpDead();
//			return true; // target died
//		}
//		return false;
//	}
//	else
//	{
//		return false;
//	}
//	return false;
//}