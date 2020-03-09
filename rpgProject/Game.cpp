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
		GetInput(player);
		Update(player);
	}

	// delete player;
	manager.CleanUp();
}

void Game::GetInput(std::shared_ptr<Actor> player)
{
	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(6);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Display Player", "Buy Something", "Create Enemy", "Display Enemies", "Attack Enemy", "Quit" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);
	switch (choice)
	{
	case 1:
		player->Display();
		break;
	case 2:
		narrator.BuySomething(player);
		break;
	case 3:
		manager.AddEnemy(manager.CreateEnemy(player->GetAverageItemLevel()));
		break;
	case 4:
		manager.DisplayAllEnemies();
		break;
	case 5:
		StartEncounter(player);
		break;
	case 6:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update(std::shared_ptr<Actor> player)
{
	player->Update();
	manager.CheckForDead();
	for (auto& enemy : manager.GetEnemies())
	{
		enemy->Update();
	}

	if (!player->LivingOrDead())
	{
		std::cout << "\nYou lost! Better luck next time!" << std::endl;
		isRunning = false;
	}
}

void Game::StartEncounter(std::shared_ptr<Actor> player)
{
	if (manager.GetTotalEnemies() == 0)
	{
		std::cout << "\nThere are no enemies!" << std::endl;
	}
	else
		Encounter newEncounter(manager, player);
}

bool Game::IsRunning()
{
	return isRunning;
}
