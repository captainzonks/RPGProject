#include "Game.h"

void Game::Initialize()
{
	srand((unsigned int)time(0)); // seed the dice rolls
	isRunning = true;
}

void Game::GameLoop()
{
	Initialize();

	narrator.StartGreeting();
	auto player = narrator.CharacterCreator();
	player->Display();

	while (IsRunning())
	{
		GetInput(*player);
		Update(*player);
	}

	delete player;
	manager.CleanUp();
}

void Game::GetInput(Actor& player)
{
	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(9);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>(
		{ 
		"Display Player", "Display Class Information", "Display Money", 
		"Display Upgrades", "Display Potions", "Buy Something", 
		"Use A Potion", "End Turn", "Quit" 
		}));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);
	switch (choice)
	{
	case 1:
		player.Display();
		break;
	case 2:
		player.DisplayClassInformation();
		break;
	case 3:
		player.myCurrency.DisplayMoney();
		break;
	case 4:
		player.myUpgrades.DisplayUpgrades();
		break;
	case 5:
		player.myInventory.DisplayPotions();
		break;
	case 6:
		narrator.BuySomething(player);
		break;
	case 7:
		player.UsePotion();
		break;
	case 8:
		std::cout << "Ending Turn\n" << std::endl;
		RandomEncounter(player);
		break;
	case 9:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update(Actor& player)
{
	player.Update();
	manager.CheckForDead();
	for (auto& enemy : manager.GetEnemies())
	{
		enemy->Update();
	}

	if (!player.LivingOrDead())
	{
		std::cout << "\nYou lost! Better luck next time!\n" << std::endl;
		isRunning = false;
	}
}

void Game::RandomEncounter(Actor& player)
{
	int randomStart{ rand() % 2 };
	int randomCount{ rand() % (player.GetAverageItemLevel() + 1) };
	if (randomStart == 1 && player.GetAverageItemLevel() != 0)
	{
		for (int i{}; i != randomCount; ++i)
		{
			manager.AddEnemy(manager.CreateEnemy(player.GetAverageItemLevel()));
		}
	}
	else if (randomStart == 1 && player.GetAverageItemLevel() == 0)
		manager.AddEnemy(manager.CreateEnemy(player.GetAverageItemLevel()));
	if (manager.GetTotalEnemies() > 0)
		Encounter newEncounter(manager, player);
}

void Game::StartEncounter(Actor& player)
{
	if (manager.GetTotalEnemies() == 0)
	{
		std::cout << "\nThere are no enemies!\n" << std::endl;
	}
	else
		Encounter newEncounter(manager, player);
}

bool Game::IsRunning()
{
	return isRunning;
}
