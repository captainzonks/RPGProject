#include "inventory.h"
#include "item.h"
#include "helper_functions.h"

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

bool inventory::add_to_inventory(std::unique_ptr<item> item)
{
	if (the_inventory_.size() != capacity_)
	{
		the_inventory_.push_back(std::move(item));
		return true;
	}
	
	std::cout << "You don't have enough room!" << std::endl;
	return false;
}

void inventory::remove_from_inventory(const unsigned item_identifier)
{
	// finds item in the inventory via the identifier using find_if() and a lambda
	const auto itr{ std::find_if(the_inventory_.begin(), the_inventory_.end(),
		[&item_identifier](const item& obj) { return obj.get_identifier() == item_identifier; })};
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

std::unique_ptr<item> inventory::get_item(const unsigned item_identifier)
{
	// finds item in the inventory via the identifier using find_if() and a lambda
	const auto itr{ std::find_if(the_inventory_.begin(), the_inventory_.end(), 
		[&item_identifier](const item& obj) { return obj.get_identifier() == item_identifier; })};
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

void inventory::equip(std::unique_ptr<item> item)
{
	switch (item->get_item_type())
	{
	case item_type::armor:
		switch (item->get_armor_slot())
		{
		case armor_slot::head:
			if(helmet_slot_ == nullptr)
			{
				helmet_slot_ = std::move(item);
				std::cout << "Equipped " << helmet_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *helmet_slot_))
				{
					std::swap(helmet_slot_, item);
					std::cout << "Equipped " << helmet_slot_->get_name() << std::endl;
				}
			}
			break;
		case armor_slot::chest:
			if(chest_slot_ == nullptr)
			{
				chest_slot_ = std::move(item);
					std::cout << "Equipped " << chest_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *chest_slot_))
				{
					std::swap(chest_slot_, item);
					std::cout << "Equipped " << chest_slot_->get_name() << std::endl;
				}
			}
			break;
		case armor_slot::legs:
			if(legs_slot_ == nullptr)
			{
				legs_slot_ = std::move(item);
				std::cout << "Equipped " << legs_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *legs_slot_))
				{
					std::swap(legs_slot_, item);
					std::cout << "Equipped " << legs_slot_->get_name() << std::endl;
				}
			}
			break;
		case armor_slot::hands:
			if(hands_slot_ == nullptr)
			{
				hands_slot_ = std::move(item);
				std::cout << "Equipped " << hands_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *hands_slot_))
				{
					std::swap(hands_slot_, item);
					std::cout << "Equipped " << hands_slot_->get_name() << std::endl;
				}
			}
			break;
		case armor_slot::feet:
			if(feet_slot_ == nullptr)
			{
				feet_slot_ = std::move(item);
				std::cout << "Equipped " << feet_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *feet_slot_))
				{
					std::swap(feet_slot_, item);
					std::cout << "Equipped " << feet_slot_->get_name() << std::endl;
				}
			}
			break;
		case armor_slot::none:
			break;
		}
		break;
	case item_type::weapon:
		switch (item->get_weapon_hand())
		{
		case weapon_hand::main:
			if(main_hand_slot_ == nullptr)
			{
				main_hand_slot_ = std::move(item);
				std::cout << "Equipped " << main_hand_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *main_hand_slot_))
				{
					std::swap(main_hand_slot_, item);
					std::cout << "Equipped " << main_hand_slot_->get_name() << std::endl;
				}
			}
			break;
		case weapon_hand::offhand:
			if(off_hand_slot_ == nullptr && main_hand_slot_->get_weapon_hand() != weapon_hand::two_handed)
			{
				off_hand_slot_ = std::move(item);
				std::cout << "Equipped " << off_hand_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *off_hand_slot_))
				{
					std::swap(off_hand_slot_, item);
					std::cout << "Equipped " << off_hand_slot_->get_name() << std::endl;
				}
			}
			break;
		case weapon_hand::either:
			if(main_hand_slot_ == nullptr)
			{
				main_hand_slot_ = std::move(item);
				std::cout << "Equipped " << main_hand_slot_->get_name() << std::endl;
			}
			else if(off_hand_slot_ == nullptr)
			{
				off_hand_slot_ = std::move(item);
				std::cout << "Equipped " << off_hand_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *main_hand_slot_))
				{
					std::swap(main_hand_slot_, item);
					std::cout << "Equipped " << main_hand_slot_->get_name() << std::endl;
				}
				else if(ask_to_swap(*item, *off_hand_slot_))
				{
					std::swap(off_hand_slot_, item);
					std::cout << "Equipped " << off_hand_slot_->get_name() << std::endl;
				}
			}
			break;
		case weapon_hand::two_handed:
			if(main_hand_slot_ == nullptr && off_hand_slot_ == nullptr)
			{
				main_hand_slot_ = std::move(item);
				std::cout << "Equipped " << main_hand_slot_->get_name() << std::endl;
			}
			else
			{
				if(ask_to_swap(*item, *main_hand_slot_))
				{
					std::swap(main_hand_slot_, item);
					std::cout << "Equipped " << main_hand_slot_->get_name() << std::endl;
				}
			}
			break;
		case weapon_hand::none:
			break;
		}
		break;
	case item_type::consumable:
	case item_type::none:
		break;
	}
}

void inventory::unequip(std::unique_ptr<item> item)
{
	switch (item->get_item_type())
	{
	case item_type::armor:
		switch (item->get_armor_slot())
		{
		case armor_slot::head:
			if(item->get_identifier() == helmet_slot_->get_identifier())
				if(add_to_inventory(std::move(item)))
					break;
				std::cout << "Could not remove " << helmet_slot_->get_name() << std::endl;
			break;
		case armor_slot::chest:
			if(item->get_identifier() == chest_slot_->get_identifier())
				if(add_to_inventory(std::move(item)))
					break;
				std::cout << "Could not remove " << chest_slot_->get_name() << std::endl;
			break;
		case armor_slot::legs:
			if(item->get_identifier() == legs_slot_->get_identifier())
				if(add_to_inventory(std::move(item)))
					break;
				std::cout << "Could not remove " << legs_slot_->get_name() << std::endl;
			break;
		case armor_slot::hands:
			if(item->get_identifier() == hands_slot_->get_identifier())
				if(add_to_inventory(std::move(item)))
					break;
				std::cout << "Could not remove " << hands_slot_->get_name() << std::endl;
			break;
		case armor_slot::feet:
			if(item->get_identifier() == feet_slot_->get_identifier())
				if(add_to_inventory(std::move(item)))
					break;
				std::cout << "Could not remove " << feet_slot_->get_name() << std::endl;
			break;
		case armor_slot::none:
			break;
		}
		break;
	case item_type::weapon:
		if(item->get_identifier() == main_hand_slot_->get_identifier())
		{
			if(add_to_inventory(std::move(item)))
				break;
			std::cout << "Could not remove " << main_hand_slot_->get_name() << std::endl;
			break;
		}
		if(item->get_identifier() == off_hand_slot_->get_identifier())
		{
			if(add_to_inventory(std::move(item)))
				break;
			std::cout << "Could not remove " << off_hand_slot_->get_name() << std::endl;
			break;
		}
		break;
	case item_type::consumable:
	case item_type::none:
		break;
	}
}

bool inventory::ask_to_swap(item& new_item, item& old_item)
{
	std::cout << "Swap " << old_item.get_name() << " for " << new_item.get_name() << "?" << std::endl;
	const auto choice = yes_or_no();
	return choice;
}
