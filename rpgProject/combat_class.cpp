#include "combat_class.h"

#include <iostream>

#include "fighter_features.h"
#include "wizard_features.h"
#include "rogue_features.h"

combat_class::combat_class(combat_class_enum const class_choice)
{
	build_class(class_choice);
}

combat_class::~combat_class()
{
	std::cout << "combat class destructor called" << std::endl;
	delete my_fighter_features_;
	delete my_wizard_features_;
	delete my_rogue_features_;
}

void combat_class::set_features(combat_class_enum const class_choice)
{
	switch (class_choice)
	{
	case combat_class_enum::fighter:
		my_fighter_features_ = new fighter_features();
		break;
	case combat_class_enum::wizard:
		my_wizard_features_ = new wizard_features();
		break;
	case combat_class_enum::rogue:
		my_rogue_features_ = new rogue_features();
	default:
		break;
	}
}

fighter_features* combat_class::access_fighter_features() const
{
	if (is_fighter())
		return my_fighter_features_;

	return nullptr;
}

wizard_features* combat_class::access_wizard_features() const
{
	if (is_wizard())
		return my_wizard_features_;

	return nullptr;
}

rogue_features* combat_class::access_rogue_features() const
{
	if (is_rogue())
		return my_rogue_features_;

	return nullptr;
}

void combat_class::build_class(combat_class_enum const class_choice)
{
	if (std::find(my_class_.begin(), my_class_.end(), class_choice) == my_class_.end())
	{
		my_class_.push_back(class_choice);
		set_features(class_choice);
	}
}

void combat_class::display_class() const
{
	if (my_class_.capacity() == 1)
		std::cout << class_strings[static_cast<int>(my_class_.at(0))];
	else
	{
		for (auto& c : my_class_)
		{
			std::cout << class_strings[static_cast<int>(c)];
		}
	}
}

void combat_class::attack()
{
	// TODO: attack functions
}
