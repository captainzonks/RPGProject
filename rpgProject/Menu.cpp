#include <iostream>

#include "Menu.h"

using std::cout;
using std::cin;
using std::endl;

int Menu::printMenu(const int* decisions, const string listOfDecisions[])
{
	int count{ 1 };
	for (int i{}; i != *decisions; ++i)
	{
		cout << count << ") " << listOfDecisions[i] << endl;
		count++;
	}
	return choiceHandler(decisions);
}

int Menu::choiceHandler(const int* decisions)
{
	int choice{};
	while (choice == 0 || (choice < *decisions && choice > *decisions))
	{
		cin >> choice;
		if (choice < 1 || choice > *decisions)
		{
			cout << "That's not a valid choice." << endl;
			choice = 0;
		}
		else
			return choice;
	}
	return choice;
}