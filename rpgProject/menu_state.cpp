#include "menu_state.h"
#include "shop_menu_state.h"
#include "combat_state.h"

menu_state menu_state::menu_state_;

void menu_state::init()
{
}

void menu_state::cleanup()
{
}

void menu_state::pause()
{
	std::cout << "MenuState pause" << std::endl;
}

void menu_state::resume()
{
	std::cout << "MenuState resume" << std::endl;
}

void menu_state::handle_events(game* game)
{
	if (choice_ != 0)
	{
		switch (choice_)
		{
		case 1:
			game->player->display();
			break;
		case 2:
			game->player->DisplayClassInformation();
			break;
		case 3:
			game->player->myCurrency.display_money();
			break;
		case 4:
			game->player->myUpgrades.DisplayUpgrades();
			break;
		case 5:
			game->player->myInventory.DisplayPotions();
			break;
		case 6:
			game->push_state(shop_menu_state::instance());
			break;
		case 7:
			game->player->use_potion();
			break;
		case 8:
			game->manager.DisplayAllEnemies();
			break;
		case 9:
			if (game->manager.GetTotalEnemies() != 0)
			{
				game->push_state(combat_state::instance());
				break;
			}
			else
				std::cout << "There are no enemies!" << std::endl;
			break;
		case 10:
			game->manager.AddEnemy(game->manager.CreateEnemy(game->player->get_average_item_level()));
			break;
		case 11:
			game->quit();
			break;
		default:
			break;
		}
	}
}

void menu_state::update(game* game)
{
	game->player->update();
}

void menu_state::draw(game* game)
{
	print_menu(this->name_, options_);

	choice_ = menu_choice(options_);
}
