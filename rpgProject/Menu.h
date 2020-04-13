#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <cctype>
#include <limits>

#include "Item.h"

class Menu
{

public:

	Menu() {}

	Menu(const std::string& name)
		: name(name) {}

	Menu(const std::string& name, Menu* parent)
		: name(name)
	{
		parent->children.push_back(this);
	}

	Menu subMenu(const std::string& name)
	{
		return Menu(name, this);
	}

	Menu* getChild(int i)
	{
		return children[i];
	}

	void AddOptions(const std::vector<std::string> options)
	{
		for (auto option : options)
			this->options.push_back(option);
	}

	int GetMenuSize()
	{
		return options.size();
	}

	void Print();
	int choiceHandler(const int& decisions);

	std::vector<Menu*> children;

	// dynamic menu creation and handling
	int PrintMenu(const int& decisions, const std::vector<std::string>& listOfDecisions);
	int UpgradeMenu(const int& decisions, const std::vector<std::unique_ptr<item>>& listOfDecisions);


private:
	std::vector<std::string> options;
	const std::string name;
};

/*
MENU CODE TEMPLATE

int choice_{};
std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
std::unique_ptr<int> const decisions = std::make_unique<int>(4);
std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Human", "Dwarf", "Elf", "Halfling" }));
choice_ = tempMenu->print_menu(*decisions, *tempDecisions);

*/