#include "Narrator.h"

void Narrator::startGreeting()
{
	cout << "=======================" << endl;
	cout << "Welcome to RPG Game " << version << endl;
	cout << "-----------------------" << endl;
}

Actor* Narrator::characterCreator()
{
	cout << "\nLet's create a character!" << endl;

	cout << "What are you?" << endl;
	int choice{};
	Menu* tempMenu = new Menu;
	const int* decisions = new int{ 4 };
	const vector<string>* tempDecisions = new vector<string>{ "Human", "Dwarf", "Elf", "Halfling" };
	choice = tempMenu->printMenu(*decisions, *tempDecisions);

	string name{};
	cout << "What's your name? ";
	cin >> name;

	Actor* player{ nullptr };

	switch (choice)
	{
	case 1:
		player = new Human(name);
		break;
	case 2:
		player = new Dwarf(name);
		break;
	case 3:
		player = new Elf(name);
		break;
	case 4:
		player = new Halfling(name);
		break;
	default:
		break;
	}

	delete decisions;
	delete tempMenu;
	delete tempDecisions;

	return player;
}

void Narrator::encounter(Actor& player, Actor& enemy)
{
	cout << "An enemy approaches!" << endl;
	cout << "Do you engage the enemy, or run?" << endl;

	Menu* tempMenu = new Menu;
	const int* decisions = new int{ 2 };
	const vector<string>* tempDecisions = new vector<string>{ "Engage!", "Run Away!" };
	
	if (tempMenu->printMenu(*decisions, *tempDecisions) == 1)
	{
		Encounter* tempEncounter = new Encounter;
		tempEncounter->encounterHandler(player, enemy);
	}
	else
		cout << "You ran away!" << endl;

	delete decisions;
	delete tempMenu;
	delete tempDecisions;
}

Item* Narrator::makeAnItem(ITEM_TYPES itemType)
{
	Item* new_item{ nullptr };
	switch (itemType)
	{
	case Narrator::ITEM_TYPES::SWORD:
		new_item = new Sword("Sword");
		break;
	case Narrator::ITEM_TYPES::SHIELD:
		new_item = new Shield("Shield", 2);
		break;
	default:
		break;
	}


	return new_item;
}

Sword* Narrator::makeASword()
{
	Sword* sword_ptr = new Sword("Sword");
	return sword_ptr;
}

// broken and obsolete - items should be classes

//void Narrator::buySomething(Actor& player)
//{
//	cout << "Welcome to fantasy shop " << version << "!" << endl;
//	cout << "=============================" << endl;
//	cout << "What would you like to purchase?" << endl;
//
//	Actor* storeNPC = new Actor;
//	vector<string> items{ "Sword", "Shield", "Potion", "Torch" };
//	storeNPC->addToInventory(items);
//	storeNPC->displayInventory();
//
//	Menu* tempMenu = new Menu;
//	const int* decisions = new int{ storeNPC->sizeOfInventory() };
//	vector<string>* tempStoreDecisions = new vector<string>[*decisions]{ storeNPC->inventory };
//	
//	player.addToInventory(tempStoreDecisions[tempMenu->printMenu(*decisions, *tempStoreDecisions) - 1]);
//
//	player.displayInventory();
//
//	delete storeNPC, tempMenu, decisions;
//	delete[] tempStoreDecisions;
//}
