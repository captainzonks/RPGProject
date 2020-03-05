#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <cmath>
#include <algorithm>
#include <vector>

/*
Standard dice rolling function; send in quantity of dice, and the d-type
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

#endif // !HELPERFUNCTIONS_H