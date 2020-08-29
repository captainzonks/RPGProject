#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <algorithm>
#include <vector>
#include <iostream>

/*
Standard dice rolling function; send in quantity of dice, and the d-damage_type_
*/
inline int roll_dice(const int &quantity, const int &dice) {
  int result{};
  for (auto i{quantity}; i > 0; --i) {
	result += (rand() % dice + 1);
  }
  return result;
}

/*
Dice rolling function for stats; it drops the lowest number from the total
*/
inline int roll_dice_ignore_lowest(const int &quantity, const int &dice) {
  std::vector<int> result{};
  int total{};
  for (auto i{quantity}; i > 0; --i) {
	result.push_back(rand() % dice + 1);
  }

  result.erase(std::min_element(std::begin(result), std::end(result)));

  for (auto &i : result)
	total += i;

  return total;
}

/*
display price in Gold, Silver, and Copper
*/
inline void display_price(const int copper) {
  int temp_gold{}, temp_silver{}, temp_copper{copper};
  temp_gold = copper / 100;
  temp_copper %= 100;
  temp_silver = temp_copper / 10;
  temp_copper %= 10;
  if (temp_gold != 0)
	std::cout << " " << temp_gold << "g";
  if (temp_silver != 0)
	std::cout << " " << temp_silver << "s";
  if (temp_copper != 0)
	std::cout << " " << temp_copper << "c";
  std::cout << std::endl;
}

inline bool yes_or_no() {
  int choice{};

  std::cout << "--------" << std::endl;
  std::cout << "1) Yes" << std::endl;
  std::cout << "2) No" << std::endl;
  std::cout << "--------" << std::endl;

  do {
	std::cout << "Please enter a number: ";
	std::cin >> choice;

	if (std::cin.fail() || choice > 2 || choice < 1) {
	  std::cout << "That's not a valid choice." << std::endl;
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
  } while (std::cin.fail() || choice > 2 || choice < 1);

  if (choice == 1)
	return true;
  return false;
}

inline void print_menu(const std::string &name, const std::vector<std::string> &options) {
  std::cout << "\n----" << name << "----" << std::endl;
  auto count{1};
  for (unsigned i{}; i != options.size(); ++i) {
	std::cout << count << ") " << options[i] << std::endl;
	count++;
  }
  std::cout << "----";
  for (unsigned i{}; i != name.length(); i++) {
	std::cout << "-";
  }
  std::cout << "----" << std::endl;
}

inline unsigned menu_choice(const std::vector<std::string> &options) {
  int choice{};

  do {
	std::cout << "Please enter a number: ";
	std::cin >> choice;

	if (std::cin.fail() || choice > static_cast<int>(options.size()) || choice < 1) {
	  std::cout << "That's not a valid choice." << std::endl;
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
  } while (std::cin.fail() || choice > static_cast<int>(options.size()) || choice < 1);

  return choice;
}

#endif