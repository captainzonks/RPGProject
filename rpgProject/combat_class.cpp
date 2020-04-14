#include "combat_class.h"

#include "fighter_functions.h"
#include "wizard_functions.h"
#include "rogue_functions.h"

combat_class::combat_class(unsigned class_choice)
{
	my_class_ = static_cast<character_class>(class_choice);
}

combat_class::~combat_class()
{
	delete fighter_;
	delete wizard_;
	delete rogue_;
}
