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
	std::cout << "MenuState Pause" << std::endl;
}

void MainMenuState::Resume()
{
	std::cout << "MenuState Resume" << std::endl;
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
			game->StartEncounter(*game->player);
			break;
		case 10:
			std::cout << "Ending Turn\n" << std::endl;
			game->RandomEncounter(*game->player);
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

}

void MainMenuState::Draw(Game* game)
{
	cout << "----" << this->name << "----" << endl;
	int count{ 1 };
	for (int i{}; i != options.size(); ++i)
	{
		cout << count << ") " << options[i] << endl;
		count++;
	}
	cout << "----";
	for (int i{}; i != this->name.length(); i++)
	{
		cout << "-";
	}
	cout << "----" << endl;

	choice = 0;
	bool valid_input{ false };

	do
	{
		cout << "Please enter a number: ";
		cin >> choice;

		if (!(valid_input = cin.good()) || choice > (int)options.size() || choice < 1)
		{
			cout << "That's not a valid choice." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || choice > (int)options.size() || choice < 1);
}
