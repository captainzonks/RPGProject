#include "MenuState.h"

MainMenuState MainMenuState::m_MainMenuState;

void MainMenuState::Init()
{
}

void MainMenuState::Cleanup()
{
}

void MainMenuState::Pause()
{
	std::cout << "MenuState pause" << std::endl;
}

void MainMenuState::Resume()
{
	std::cout << "MenuState resume" << std::endl;
}

void MainMenuState::HandleEvents(Game* game)
{
	if (choice != 0)
	{
		switch (choice)
		{
		case 1:
			game->player->Display();
			break;
		case 2:
			game->player->DisplayClassInformation();
			break;
		case 3:
			game->player->myCurrency.DisplayMoney();
			break;
		case 4:
			game->player->myUpgrades.DisplayUpgrades();
			break;
		case 5:
			game->player->myInventory.DisplayPotions();
			break;
		case 6:
			game->PushState(ShopMenuState::Instance());
			break;
		case 7:
			game->player->UsePotion();
			break;
		case 8:
			game->manager.DisplayAllEnemies();
			break;
		case 9:
			if (game->manager.GetTotalEnemies() != 0)
			{
				game->PushState(CombatState::Instance());
				break;
			}
			else
				std::cout << "There are no enemies!" << std::endl;
			break;
		case 10:
			game->manager.AddEnemy(game->manager.CreateEnemy(game->player->GetAverageItemLevel()));
			break;
		case 11:
			game->Quit();
			break;
		default:
			break;
		}
	}
}

void MainMenuState::Update(Game* game)
{
	game->player->Update();
}

void MainMenuState::Draw(Game* game)
{
	PrintMenu(this->name, options);

	choice = MenuChoice(options);
}
