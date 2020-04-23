#include "character.h"

#include <iostream>

character::character(attributes* new_attributes, currency* new_currency, character_job* new_combat_class)
	: my_attributes_(new_attributes), my_currency_(new_currency), my_job_(new_combat_class)
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
	delete my_job_;
}

void character::update() const
{
	if (is_alive_)
		my_inventory_->update();
}

void character::display() const
{
	// name header
	std::cout << "\n====" << my_attributes_->get_name() << "====" << std::endl;
	// basic stats
	std::cout << "    " << my_attributes_->get_race_string() << " ";
	my_job_->display_jobs();
	std::cout << std::endl;
	std::cout << "    " << my_attributes_->get_current_health() << " HP / " << my_attributes_->get_max_health() << " HP" << std::endl;
	std::cout << "    " << my_attributes_->get_current_exp() << " XP" << std::endl;
	// ability stats
	std::cout << "    " << my_attributes_->get_strength() << " Strength"
	<< " (" << std::showpos << my_attributes_->get_strength_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << my_attributes_->get_dexterity() << " Dexterity"
	<< " (" << std::showpos << my_attributes_->get_dexterity_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << my_attributes_->get_constitution() << " Constitution"
	<< " (" << std::showpos << my_attributes_->get_constitution_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << my_attributes_->get_intelligence() << " Intelligence"
	<< " (" << std::showpos << my_attributes_->get_intelligence_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << my_attributes_->get_wisdom() << " Wisdom"
	<< " (" << std::showpos << my_attributes_->get_wisdom_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << my_attributes_->get_charisma() << " Charisma"
	<< " (" << std::showpos << my_attributes_->get_charisma_mod() << ")" << std::noshowpos << std::endl;
	// footer
	std::cout << "====";
	for (auto c : my_attributes_->get_name())
		std::cout << "=";
	std::cout << std::endl;
}

void character::move(std::vector<double> destination)
{
	const auto my_speed = access_attributes().get_speed();
	auto dx = destination.at(0) - my_location_.at(0);
	auto dy = destination.at(1) - my_location_.at(1);

	const auto r = sqrt(dx*dx + dy*dy);

	if (r < my_speed)
	{
		my_location_.at(0) = destination.at(0);
		my_location_.at(1) = destination.at(1);

		std::cout << "I have arrived at (" << destination.at(0) << ", " << destination.at(1) << ")" << std::endl;

		return;
	}

	// normalize
	if (r > 0)
	{	
		dx /= r;
		dy /= r;
	}

	my_location_.at(0) += (my_speed) * dx;

	my_location_.at(1) += (my_speed) * dy;

	std::cout << "My new position is now (" << static_cast<int>(my_location_.at(0)) << ", " << static_cast<int>(my_location_.at(1)) << ")" << std::endl;
}
