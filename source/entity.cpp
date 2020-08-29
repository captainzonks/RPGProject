#include "entity.h"
#include "component.h"

#include <iostream>

#include "attributes_component.h"
#include "inventory_component.h"
#include "job_component.h"

entity::entity(std::string name)
	: name(std::move(name)) {
  this->is_active_ = true;
}

entity::~entity() {
  std::cout << "entity destructor called" << std::endl;

  for (auto component : components_)
	delete component;
}

void entity::update() const {
  for (auto &component : components_)
	component->update();
}

void entity::render() {
  for (auto &component : components_)
	component->render();
}

void entity::destroy() {
  this->is_active_ = false;
}

void entity::list_all_components() const {
  for (const auto map_element : component_type_map_)
	std::cout << "  Component<" << map_element.first->name() << ">" << std::endl;
}

void entity::display() {
  // name header
  std::cout << "\n====" << get_component<attributes_component>()->get_name() << "====" << std::endl;
  // basic stats
  std::cout << "    " << get_component<attributes_component>()->get_race_string() << " ";
  get_component<job_component>()->display_jobs();
  std::cout << std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_current_health() << " HP / "
			<< get_component<attributes_component>()->get_max_health() << " HP" << std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_current_exp() << " XP" << std::endl;
  // ability stats
  std::cout << "    " << get_component<attributes_component>()->get_strength() << " Strength"
			<< " (" << std::showpos << get_component<attributes_component>()->get_strength_mod() << ")"
			<< std::noshowpos << std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_dexterity() << " Dexterity"
			<< " (" << std::showpos << get_component<attributes_component>()->get_dexterity_mod() << ")"
			<< std::noshowpos << std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_constitution() << " Constitution"
			<< " (" << std::showpos << get_component<attributes_component>()->get_constitution_mod() << ")"
			<< std::noshowpos << std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_intelligence() << " Intelligence"
			<< " (" << std::showpos << get_component<attributes_component>()->get_intelligence_mod() << ")"
			<< std::noshowpos << std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_wisdom() << " Wisdom"
			<< " (" << std::showpos << get_component<attributes_component>()->get_wisdom_mod() << ")" << std::noshowpos
			<< std::endl;
  std::cout << "    " << get_component<attributes_component>()->get_charisma() << " Charisma"
			<< " (" << std::showpos << get_component<attributes_component>()->get_charisma_mod() << ")"
			<< std::noshowpos << std::endl;
  // footer
  std::cout << "====";
  for (auto c : get_component<attributes_component>()->get_name())
	std::cout << "=";
  std::cout << std::endl;
}