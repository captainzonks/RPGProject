#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

class Menu
{
public:

	// dynamic menu creation and handling
	int printMenu(const int& decisions, const vector<string>& listOfDecisions);
	int choiceHandler(const int& decisions);

	

};

/*
MENU CODE TEMPLATE

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

*/