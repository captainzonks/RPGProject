#pragma once

#include <string>

using std::string;

class Menu
{
public:
	int printMenu(const int& decisions, const string* listOfDecisions[]);
	int choiceHandler(const int& decisions);

};

