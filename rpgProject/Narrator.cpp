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
	const string* tempYorNdecision = new string[4]{ "Human", "Dwarf", "Elf", "Halfling" };
	choice = tempMenu->printMenu(*decisions, &tempYorNdecision);

	string name{};
	cout << "What's your name? ";
	cin >> name;

	Actor* player{ nullptr };

	switch (choice)
	{
	case 1:
		player = new Human(name);
	default:
		break;
	}

	delete decisions;
	delete tempMenu;
	delete[] tempYorNdecision;

	return player;
}

void Narrator::encounter(Actor& player, Actor& enemy)
{
	cout << "An enemy approaches!" << endl;
	cout << "Do you engage the enemy, or run?" << endl;

	Menu* tempMenu = new Menu;
	const int* decisions = new int{ 2 };
	const string* tempYorNdecision = new string[2]{ "Engage!", "Run Away!" };
	
	if (tempMenu->printMenu(*decisions, &tempYorNdecision) == 1)
	{
		Encounter* tempEncounter = new Encounter;
		tempEncounter->encounterHandler(player, enemy);
	}
	else
		cout << "You ran away!" << endl;

	delete decisions;
	delete tempMenu;
	delete[] tempYorNdecision;
}

void Narrator::buySomething(Actor& player)
{
	cout << "\nWelcome to fantasy shop " << version << "!" << endl;
	cout << "=============================" << endl;

	Menu* tempMenu = new Menu;
	const int* decisions = new int{ 4 };
	const string* tempStoreDecisions = new string[*decisions]{ "Sword", "Shield", "Potion", "Torch" };

	player.addToInventory(tempStoreDecisions[tempMenu->printMenu(*decisions, &tempStoreDecisions) - 1]);

	player.displayInventory();

}
