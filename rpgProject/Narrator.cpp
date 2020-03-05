#include "Narrator.h"

void Narrator::startGreeting()
{
	cout << "=======================" << endl;
	cout << "Welcome to RPG Game " << version << endl;
	cout << "-----------------------" << endl;
}

std::shared_ptr<Actor> Narrator::characterCreator()
{
	cout << "\nLet's create a character!" << endl;

	cout << "What are you?" << endl;
	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(4);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Human", "Dwarf", "Elf", "Halfling" }));
	choice = tempMenu->printMenu(*decisions, *tempDecisions);

	string name{};
	cout << "What's your name? ";
	cin >> name;

	std::shared_ptr<Actor> new_player{ nullptr };

	switch (choice)
	{
	case 1:
		new_player = std::make_shared<Human>(name);
		break;
	case 2:
		new_player = std::make_shared<Dwarf>(name);
		break;
	case 3:
		new_player = std::make_shared<Elf>(name);
		break;
	case 4:
		new_player = std::make_shared<Halfling>(name);
		break;
	default:
		break;
	}

	return new_player;
}

//void Narrator::encounter(Actor& player, Actor& enemy)
//{
//	cout << "An enemy approaches!" << endl;
//	cout << "Do you engage the enemy, or run?" << endl;
//
//	Menu* tempMenu = new Menu;
//	const int* decisions = new int{ 2 };
//	const vector<string>* tempDecisions = new vector<string>{ "Engage!", "Run Away!" };
//	
//	if (tempMenu->printMenu(*decisions, *tempDecisions) == 1)
//	{
//		Encounter* tempEncounter = new Encounter;
//		tempEncounter->encounterHandler(player, enemy);
//	}
//	else
//		cout << "You ran away!" << endl;
//
//	delete decisions;
//	delete tempMenu;
//	delete tempDecisions;
//}

std::unique_ptr<Item> Narrator::makeAnItem(ITEM_TYPES itemType)
{
	std::unique_ptr<Item> new_item{ nullptr };
	switch (itemType)
	{
	case Narrator::ITEM_TYPES::SWORD:
		new_item = std::make_unique<Sword>("Sword", 6);
		break;
	case Narrator::ITEM_TYPES::SHIELD:
		new_item = std::make_unique<Shield>("Shield", 2);
		break;
	default:
		break;
	}


	return new_item;
}

//Sword* Narrator::makeASword()
//{
//	Sword* sword_ptr = new Sword("Sword");
//	return sword_ptr;
//}

// broken and obsolete - items should be classes

void Narrator::buySomething(std::shared_ptr<Actor> player)
{
	cout << "Welcome to fantasy shop " << version << "!" << endl;
	cout << "=============================" << endl;
	cout << "What would you like to purchase?" << endl;
	cout << "1) Sword - 2 silver" << endl;
	cout << "2) Shield - 3 gold" << endl;
	cout << "---------------" << endl;
	cout << "Please enter a number: ";
	std::unique_ptr<Sword> sword = std::make_unique<Sword>();
	std::unique_ptr<Shield> shield = std::make_unique<Shield>();
	int choice{};
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (CheckPrice(player, 20))
		{
			player->myInventory.GetWeapon(std::move(sword));
			break;
		}
		else
		{
			std::cout << "You can't afford that." << std::endl;
			break;
		}
	case 2:
		if (CheckPrice(player, 300))
		{
			player->myInventory.GetArmor(std::move(shield));
			break;
		}
		else
		{
			std::cout << "You can't afford that." << std::endl;
			break;
		}
	default:
		cout << "Invalid entry" << endl;
		break;
	}
}

bool Narrator::CheckPrice(std::shared_ptr<Actor> player, int price)
{
	if (price > player->myCurrency.getCopper())
		return false;
	else
		return true;
}
