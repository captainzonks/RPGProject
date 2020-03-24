#include "Game.h"

void Game::Initialize()
{
	srand((unsigned int)time(0)); // seed the dice rolls
	isRunning = true;
}

void Game::Cleanup()
{
	// cleanup all the states
	while (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}
}

void Game::ChangeState(GameState* state)
{
	// cleanup the current state
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PushState(GameState* state)
{
	// pause current state
	if (!states.empty())
	{
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PopState()
{
	// cleanup the current state
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty())
	{
		states.back()->Resume();
	}
}

void Game::GameLoop()
{
	Initialize();

	narrator.StartGreeting();
	player = narrator.CharacterCreator();
	player->Display();

	while (IsRunning())
	{
		GetInput(player);
		Update(player);
	}

	delete player;
	manager.CleanUp();
}

void Game::GetInput(Actor& player)
{
	//int choice{};
	//std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	//std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>(
	//	{
	//	"Display Player", "Display Class Information", "Display Money",
	//	"Display Upgrades", "Display Potions", "Buy Something",
	//	"Use A Potion", "Display Enemies", "Attack", "Random Encounter", "Quit"
	//	}));
	//std::unique_ptr<int> const decisions = std::make_unique<int>(tempDecisions->size());
	//choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	std::unique_ptr<Menu> mainMenu = std::make_unique<Menu>("Main Menu");
	std::vector<string> options{ "Display Player", "Display Class Information",
		"Display Money", "Display Upgrades", "Display Potions", "Buy Something",
		"Use A Potion", "Display Enemies", "Attack", "Random Encounter", "Quit" };
	mainMenu->AddOptions(options);
	mainMenu->Print();

	switch (mainMenu->choiceHandler(mainMenu->GetMenuSize()))
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
		manager.DisplayAllEnemies();
		break;
	case 9:
		StartEncounter(player);
		break;
	case 10:
		std::cout << "Ending Turn\n" << std::endl;
		RandomEncounter(player);
		break;
	case 11:
		isRunning = false;
		break;
	default:
		std::cout << "That's not a valid choice." << std::endl;
		break;
	}
}

void Game::HandleEvents()
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void Game::Update()
{
	// let the state update the game
	states.back()->Update(this);

	//player.Update();
	//manager.CheckForDead();
	//for (auto& enemy : manager.GetEnemies())
	//{
	//	enemy->Update();
	//}

	//if (!player.LivingOrDead())
	//{
	//	std::cout << "\nYou lost! Better luck next time!\n" << std::endl;
	//	isRunning = false;
	//}
}

void Game::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
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
	else
		std::cout << "\nThe night passed peacefully. It's a new day." << std::endl;
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
