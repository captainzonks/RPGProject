#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

#include "Item.h"

class Menu
{
public:
	// dynamic menu creation and handling
	int PrintMenu(const int& decisions, const vector<string>& listOfDecisions);
	int PrintMenu(const int& decisions, const vector<std::unique_ptr<Item>>& listOfDecisions);
	int choiceHandler(const int& decisions);

};

/*
MENU CODE TEMPLATE

int choice{};
std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
std::unique_ptr<int> const decisions = std::make_unique<int>(4);
std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Human", "Dwarf", "Elf", "Halfling" }));
choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

*/