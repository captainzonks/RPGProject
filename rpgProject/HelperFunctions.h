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

#endif // !HELPERFUNCTIONS_H