#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

/*
Standard dice rolling function; send in quantity of dice, and the d-damageType
*/
inline int RollDice(const int& quantity, const int& dice)
{
	int result{};
	for (int i{ quantity }; i > 0; --i)
	{
		result += (rand() % dice + 1);
	}
	return result;
}

/*
Dice rolling function for stats; it drops the lowest number from the total
*/
inline int RollDiceIgnoreLowest(const int& quantity, const int& dice)
{
	std::vector<int> result{};
	int total{};
	for (int i{ quantity }; i > 0; --i)
	{
		result.push_back(rand() % dice + 1);
	}

	result.erase(std::min_element(std::begin(result), std::end(result)));

	for (auto& i : result)
		total += i;

	return total;
}

/*
Display price in Gold, Silver, and Copper
*/
inline void DisplayPrice(const int copper)
{
	int tempGold{}, tempSilver{}, tempCopper{ copper };
	tempGold = copper / 100;
	tempCopper %= 100;
	tempSilver = tempCopper / 10;
	tempCopper %= 10;
	if (tempGold != 0)
		std::cout << " " << tempGold << "g";
	if (tempSilver != 0)
		std::cout << " " << tempSilver << "s";
	if (tempCopper != 0)
		std::cout << " " << tempCopper << "c";
	std::cout << std::endl;
}

inline void PrintMenu(std::string name, std::vector<std::string> options)
{
	std::cout << "\n----" << name << "----" << std::endl;
	int count{ 1 };
	for (int i{}; i != options.size(); ++i)
	{
		std::cout << count << ") " << options[i] << std::endl;
		count++;
	}
	std::cout << "----";
	for (int i{}; i != name.length(); i++)
	{
		std::cout << "-";
	}
	std::cout << "----" << std::endl;
}

inline int MenuChoice(std::vector<std::string> options)
{
	int choice{};
	bool valid_input{ false };

	do
	{
		std::cout << "Please enter a number: ";
		std::cin >> choice;

		if (!(valid_input = std::cin.good()) || choice > static_cast<int>(options.size()) || choice < 1)
		{
			std::cout << "That's not a valid choice." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || choice > static_cast<int>(options.size()) || choice < 1);

	return choice;
}

#endif // !HELPERFUNCTIONS_H