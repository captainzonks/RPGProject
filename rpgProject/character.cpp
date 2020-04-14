#include "character.h"

#include "attributes.h"
#include "combat_class.h"
#include "currency.h"
#include "inventory.h"

character::character()
{
	is_alive_ = true;
}

character::~character()
{
	delete my_attributes_;
	delete my_inventory_;
	delete my_currency_;
	delete my_combat_class_;
}
