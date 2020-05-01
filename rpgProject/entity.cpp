#include "entity.h"
#include "component.h"

#include <iostream>

#include "attributes_component.h"
#include "inventory_component.h"
#include "job_component.h"

entity::entity(std::string name, const layer_type layer)
	: name(std::move(name)), layer(layer)
{
	this->is_active_ = true;
}

entity::~entity()
{
	std::cout << "entity destructor called" << std::endl;

	for (auto component : components_)
		delete component;
}

void entity::update(const float delta_time) const
{
	for (auto& component : components_)
		component->update(delta_time);
}

void entity::draw()
{
	for (auto& component: components_)
		component->draw();
}

void entity::destroy()
{
	this->is_active_ = false;
}

void entity::list_all_components() const
{
	for (const auto map_element : component_type_map_)
		std::cout << "  Component<" << map_element.first->name() << ">" << std::endl;
}

void entity::display() 
{

	
	// name header
	std::cout << "\n====" << get_component<attributes_component>()->get_name() << "====" << std::endl;
	// basic stats
	std::cout << "    " << get_component<attributes_component>()->get_race_string() << " ";
	get_component<job_component>()->display_jobs();
	std::cout << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_current_health() << " HP / " << get_component<attributes_component>()->get_max_health() << " HP" << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_current_exp() << " XP" << std::endl;
	// ability stats
	std::cout << "    " << get_component<attributes_component>()->get_strength() << " Strength"
	<< " (" << std::showpos << get_component<attributes_component>()->get_strength_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_dexterity() << " Dexterity"
	<< " (" << std::showpos << get_component<attributes_component>()->get_dexterity_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_constitution() << " Constitution"
	<< " (" << std::showpos << get_component<attributes_component>()->get_constitution_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_intelligence() << " Intelligence"
	<< " (" << std::showpos << get_component<attributes_component>()->get_intelligence_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_wisdom() << " Wisdom"
	<< " (" << std::showpos << get_component<attributes_component>()->get_wisdom_mod() << ")" << std::noshowpos << std::endl;
	std::cout << "    " << get_component<attributes_component>()->get_charisma() << " Charisma"
	<< " (" << std::showpos << get_component<attributes_component>()->get_charisma_mod() << ")" << std::noshowpos << std::endl;
	// footer
	std::cout << "====";
	for (auto c : get_component<attributes_component>()->get_name())
		std::cout << "=";
	std::cout << std::endl;
}

//void entity::move(std::vector<double> destination)
//{
//	const auto my_speed = my_attributes_->get_speed();
//	auto dx = destination.at(0) - my_location_.at(0);
//	auto dy = destination.at(1) - my_location_.at(1);
//
//	const auto r = sqrt(dx*dx + dy*dy);
//
//	if (r < my_speed)
//	{
//		my_location_.at(0) = destination.at(0);
//		my_location_.at(1) = destination.at(1);
//
//		std::cout << "I have arrived at (" << destination.at(0) << ", " << destination.at(1) << ")" << std::endl;
//
//		return;
//	}
//
//	// normalize
//	if (r > 0)
//	{	
//		dx /= r;
//		dy /= r;
//	}
//
//	my_location_.at(0) += (my_speed) * dx;
//
//	my_location_.at(1) += (my_speed) * dy;
//
//	std::cout << "My new position is now (" << static_cast<int>(my_location_.at(0)) << ", " << static_cast<int>(my_location_.at(1)) << ")" << std::endl;
//}
