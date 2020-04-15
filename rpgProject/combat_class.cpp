#include "combat_class.h"

#include "fighter_functions.h"
#include "wizard_functions.h"
#include "rogue_functions.h"

combat_class::combat_class(const unsigned class_choice)
{
	build_class(class_choice);
}

combat_class::~combat_class()
{
	my_fighter_functions_ = nullptr;
	my_wizard_functions_ = nullptr;
	my_rogue_functions_ = nullptr;
}

void combat_class::build_class(const unsigned class_choice)
{
	switch (static_cast<character_class>(class_choice))
	{
	case character_class::fighter:
		my_fighter_functions_ = fighter_functions::instance();
		my_class_.try_emplace(character_class::fighter, 1);
		break;
	case character_class::wizard:
		my_wizard_functions_ = wizard_functions::instance();
		my_class_.try_emplace(character_class::wizard, 1);
		break;
	case character_class::rogue:
		my_rogue_functions_ = rogue_functions::instance();
		my_class_.try_emplace(character_class::rogue, 1);
		break;
	case character_class::none:
	default:
		break;
	}
}

void combat_class::attack()
{
	
}
