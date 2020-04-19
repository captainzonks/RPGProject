//#include "Menu.h"
//
//void Menu::Print()
//{
//	std::cout << "----" << this->name << "----" << std::endl;
//	int count{ 1 };
//	for (int i{}; i != options.size(); ++i)
//	{
//		std::cout << count << ") " << options[i] << std::endl;
//		count++;
//	}
//	std::cout << "----";
//	for (int i{}; i != this->name.length(); i++)
//	{
//		cout << "-";
//	}
//	std::cout << "----" << std::endl;
//}
//
//int Menu::PrintMenu(const int& decisions, const std::vector<std::string>& listOfDecisions)
//{
//	std::cout << "--------" << std::endl;
//	int count{ 1 };
//	for (int i{}; i != decisions; ++i)
//	{
//		cout << count << ") " << listOfDecisions[i] << std::endl;
//		count++;
//	}
//	std::cout << "--------" << std::endl;
//	return choiceHandler(decisions);
//}
//
//int Menu::UpgradeMenu(const int& decisions, const std::vector<std::unique_ptr<item>>& listOfDecisions)
//{
//	cout << "--------" << std::endl;
//	int count{ 1 };
//	for (int i{}; i != decisions; ++i)
//	{
//		cout << count << ") " << *(listOfDecisions.at(i)) << " : " << listOfDecisions.at(i)->GetValue() / 100 << " gold" << endl;
//		count++;
//	}
//	std::cout << "--------" << std::endl;
//	return choiceHandler(decisions);
//}
//
//int Menu::choiceHandler(const int& decisions)
//{
//	int choice{};
//	bool valid_input{ false };
//
//	do
//	{
//		std::cout << "Please enter a number: ";
//		std::cin >> choice;
//
//		if (!(valid_input = std::cin.good()) || choice > decisions || choice < 1)
//		{
//			std::cout << "That's not a valid choice_." << std::endl;
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		}
//	} while (!valid_input || choice > decisions || choice < 1);
//
//	return choice;
//}