//#include "Encounter.h"
//
//Encounter::Encounter(EnemyManager& manager, actor& player)
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
//	actor* temp{ nullptr };
//	for (size_t i{}; i < initiativeOrder.size(); ++i)
//	{
//		for (size_t j{ i + 1 }; j < initiativeOrder.size(); ++j)
//		{
//			if (initiativeOrder.at(i)->get_initiative() < initiativeOrder.at(j)->get_initiative())
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
//	// debug display initiative order to check
//	for (auto actor : initiativeOrder)
//	{
//		std::cout << actor->get_name() << " Initiative: " << actor->get_initiative() << std::endl;
//	}
//}
//
//void Encounter::BeginEncounter(EnemyManager& manager, actor& player)
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
//			actor* target{ RandomTargetPicker(*attacker) };
//			std::vector<actor*>::iterator itr{ std::find(initiativeOrder.begin(), initiativeOrder.end(), target) };
//			if (EncounterHandler(*attacker, *target))
//			{
//				if (target->get_name() == player.get_name())
//				{
//					std::cout << "You Died!" << std::endl;
//					std::cout << "\nYou were killed by: " << std::endl;
//					attacker->display();
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
//actor* Encounter::RandomTargetPicker(actor& attacker)
//{
//	actor* target{ initiativeOrder.at(rand() % initiativeOrder.size()) };
//	if (target->get_name() == attacker.get_name())
//		return RandomTargetPicker(attacker);
//
//	return target;
//}
//
//// returns TRUE if defender dies, FALSE if defender still lives
//bool Encounter::EncounterHandler(actor& attacker, actor& defender)
//{
//	if (Attack::MakeAnAttack(attacker, defender))
//	{
//		if (!defender.is_alive())
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
