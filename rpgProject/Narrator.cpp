#include "Narrator.h"
#include "Encounter.h"

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

void Narrator::menuBuilder(int decisions, std::string listOfDecisions[])
{
	int count{ 1 };
	for (int i{}; i <= decisions; ++i)
	{
		cout << count << ") " << listOfDecisions[i] << endl;
		count++;
	}
}

void Narrator::characterCreator()
{
	cout << "\nLet's create a character!" << endl;
}

void Narrator::encounter(Actor* player, Actor* enemy)
{
	cout << "An enemy approaches!" << endl;
	cout << "Do you engage the enemy, or run?" << endl;

	// calls the menu, passes the decisions (2 in this case, Yes or No)
	std::string* tempYorNdecision = new std::string[2]{ "Y", "N" };
	menuBuilder(tempYorNdecision->length(), tempYorNdecision);

	// can a Y or N decision be made into a separate method? return a true or false
	char choice{};
	while (tolower(choice) != 'y' && tolower(choice) != 'n')
	{
		cin >> choice;
		switch (tolower(choice))
		{
		case 'y':
		{
			Encounter* temp = new Encounter;
			temp->encounterHandler(player, enemy);
			delete temp;
			break;
		}
		case 'n':
			cout << "You ran away!" << endl;
			break;
		default:
			cout << "Input not recognized." << endl;
			break;
		}
	}

	delete[] tempYorNdecision;
}
