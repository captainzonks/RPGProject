#include "character.h"
#include "attributes.h"
#include "inventory.h"
#include "currency.h"
#include "combat_class.h"

character::character()
{
	is_alive_ = true;
	my_attributes_ = new attributes;
	my_inventory_ = new inventory;
	my_currency_ = new currency;
	my_combat_class_ = new combat_class;
}

character::~character()
{
	delete my_attributes_;
	delete my_inventory_;
	delete my_currency_;
	delete my_combat_class_;
}