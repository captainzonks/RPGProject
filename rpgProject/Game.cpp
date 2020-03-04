#include "Game.h"

void Game::Initialize()
{
	srand((unsigned int)time(0)); // seed the dice rolls
	isRunning = true;
}

void Game::GameLoop()
{
	Initialize();

	narrator.startGreeting();
	auto player = narrator.characterCreator();
	player->display();

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
	std::unique_ptr<int> const decisions = std::make_unique<int>(5);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Display Player", "Create Enemy", "Display Enemies", "Attack Enemy", "Quit" }));
	choice = tempMenu->printMenu(*decisions, *tempDecisions);
	switch (choice)
	{
	case 1:
		player->display();
		break;
	case 2:
		manager.AddEnemy(manager.CreateEnemy());
		break;
	case 3:
		manager.DisplayAllEnemies();
		break;
	case 4:
		StartEncounter(player);
		break;
	case 5:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update(std::shared_ptr<Actor> player)
{
	manager.CheckForDead();
	if (!player->livingOrDead())
	{
		std::cout << "You lost! Better luck next time!" << std::endl;
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
