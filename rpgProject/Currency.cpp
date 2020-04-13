#include "currency.h"

#include <iostream>

unsigned currency::get_gold() const
{
	return copper_ / 100;
}

unsigned currency::get_silver() const
{
	return copper_ / 10;
}

unsigned currency::get_copper() const
{
	return copper_;
}

void currency::display_money() const
{
	auto temp_copper = copper_;
	const auto gold = temp_copper / 100;
	temp_copper %= 100;
	const auto silver = temp_copper / 10;
	temp_copper %= 10;

	std::cout << "\n====MONEY====" << std::endl;
	std::cout << "Gold   : " << gold << std::endl;
	std::cout << "Silver : " << silver << std::endl;
	std::cout << "Copper : " << temp_copper << std::endl;
	std::cout << "=============" << std::endl;
}

void currency::add_money(const unsigned copper)
{
	copper_ += copper;
}

void currency::subtract_money(const unsigned copper)
{
	if (copper > copper_)
		std::cout << "You don't have enough money!" << std::endl;
	else
		copper_ -= copper;
}