#include "item.h"

#include <iostream>

void item::display()
{
	std::cout << "\n|~~~~~" << name_ << "~~~~~|" << std::endl;
	std::cout << "|-----";
	for (auto c : name_)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "    " << item_type_strings[static_cast<int>(item_type_)] << std::endl;
	if(this->item_type_ == item_type::weapon)
	{
		
		std::cout << "    " << damage_dice_.at(0) << "d" << damage_dice_.at(1) << std::endl;
		std::cout << "    " << damage_type_strings[static_cast<int>(damage_type_)] << std::endl;
	}
	if(this->item_type_ == item_type::armor)
	{
		std::cout << "    " << armor_type_string[static_cast<int>(armor_type_)] << std::endl;
		std::cout << "    " << std::showpos << armor_value_ << " AC" << std::endl;
	}
	if(this->item_type_ == item_type::consumable)
	{
		std::cout << "    " << health_change_value_ << " HP" << std::endl;
	}
	std::cout << "    Level " << level_ << std::endl;
	std::cout << "    Value: " << value_ << " cp" << std::endl;
	std::cout << "    Weight: " << weight_ << " lbs" << std::endl;
	std::cout << "|-----";
	for (auto c : name_)
		std::cout << "-";
	std::cout << std::endl;
}
