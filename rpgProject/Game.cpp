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

	delete player;
	manager.CleanUp();
}

void Game::GetInput(Actor* player)
{
	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(4);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Display Player", "Create Enemy", "Display Enemies", "Quit" }));
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
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update(Actor* player)
{
	
}

bool Game::IsRunning()
{
	return isRunning;
}
