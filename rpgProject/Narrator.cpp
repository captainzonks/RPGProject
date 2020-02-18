#include "Narrator.h"
#include "Encounter.h"
#include "Menu.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Narrator::startGreeting()
{
	cout << "=======================" << endl;
	cout << "Welcome to RPG Game " << version << endl;
	cout << "-----------------------" << endl;
}

void Narrator::characterCreator()
{
	cout << "\nLet's create a character!" << endl;
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
