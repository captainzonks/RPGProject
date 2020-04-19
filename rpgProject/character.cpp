#include "character.h"

#include <iostream>

character::character(attributes* new_attributes, currency* new_currency, combat_class* new_combat_class)
	: my_attributes_(new_attributes), my_currency_(new_currency), my_combat_class_(new_combat_class)
{
	my_inventory_ = new inventory();
	is_alive_ = true;
}

character::~character()
{
	std::cout << "character destructor called" << std::endl;
	delete my_attributes_;
	delete my_inventory_;
	delete my_currency_;
	delete my_combat_class_;
}

void character::display() const
{
	// name header
	std::cout << "\n====" << my_attributes_->get_name() << "====" << std::endl;
	// basic stats
	std::cout << "\t" << my_attributes_->get_race_string() << std::endl;
	std::cout << "\t" << my_attributes_->get_current_health() << " HP / " << my_attributes_->get_max_health() << " HP" << std::endl;
	std::cout << "\t" << my_attributes_->get_current_exp() << " XP" << std::endl;
	// ability stats
	std::cout << "\t" << my_attributes_->get_strength() << " Strength"
	<< " (" << std::showpos << my_attributes_->get_strength_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "\t" << my_attributes_->get_dexterity() << " Dexterity"
	<< " (" << std::showpos << my_attributes_->get_dexterity_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "\t" << my_attributes_->get_constitution() << " Constitution"
	<< " (" << std::showpos << my_attributes_->get_constitution_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "\t" << my_attributes_->get_intelligence() << " Intelligence"
	<< " (" << std::showpos << my_attributes_->get_intelligence_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "\t" << my_attributes_->get_wisdom() << " Wisdom"
	<< " (" << std::showpos << my_attributes_->get_wisdom_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "\t" << my_attributes_->get_charisma() << " Charisma"
	<< " (" << std::showpos << my_attributes_->get_charisma_mod() << ")" << std::noshowpos << std::endl;
	// footer
	std::cout << "====";
	for (auto c : my_attributes_->get_name())
		std::cout << "=";
	std::cout << std::endl;
}
