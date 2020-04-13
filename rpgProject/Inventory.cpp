#include "inventory.h"

#include <iostream>

inventory::~inventory()
{
	the_inventory_.clear();
	std::cout << "inventory destructor called" << std::endl;
}

void inventory::set_capacity(const int new_capacity)
{
	capacity_ = new_capacity;
}

unsigned int inventory::get_capacity() const
{
	return capacity_;
}

int inventory::total_items_in_inventory() const
{
	return the_inventory_.size();
}

void inventory::add_to_inventory(std::unique_ptr<item> item)
{
	if (the_inventory_.size() != capacity_)
		the_inventory_.push_back(std::move(item));
	else
		std::cout << "You don't have enough room!" << std::endl;
}

void inventory::remove_from_inventory(const std::string& item_name)
{
	const auto itr{ std::find(the_inventory_.begin(), the_inventory_.end(), item_name) };
	the_inventory_.erase(the_inventory_.begin() + std::distance(the_inventory_.begin(), itr));
}

void inventory::display_inventory() const
{
	std::cout << "=====INVENTORY=====" << std::endl;
	auto counter{ 1 };
	if (the_inventory_.empty())
	{
		std::cout << "EMPTY" << std::endl;
	}
	else
	{
		for (auto& i : the_inventory_)
		{
			std::cout << counter << ": " << i->get_name() << std::endl;
			counter++;
		}
	}
	std::cout << "===================" << std::endl;
}

std::unique_ptr<item> inventory::get_item(const std::string& item_name)
{
	const auto itr{ std::find(the_inventory_.begin(), the_inventory_.end(), item_name) };
	return std::move(*itr);
}

int inventory::return_ammo() const
{
	return ammunition_;
}

void inventory::subtract_ammo()
{
	ammunition_--;
}

void inventory::add_ammo(const int amount)
{
	ammunition_ += amount;
}