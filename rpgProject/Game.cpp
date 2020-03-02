#include "Game.h"

void Game::Initialize()
{
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
		GetInput();
		Update(player);
	}

	delete player;
}

void Game::GetInput()
{
	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(1);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Quit" }));
	choice = tempMenu->printMenu(*decisions, *tempDecisions);

	switch (choice)
	{
	case 1:
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