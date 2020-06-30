#include "entity_manager.h"

#include <iostream>
#include <memory>


#include "attributes_component.h"
#include "entity.h"

entity_manager entity_manager::entity_manager_instance_;

entity& entity_manager::add_entity(std::string entity_name, layer_type layer)
{
	auto new_entity = std::make_shared<entity>(std::move(entity_name), layer);
	entities_.emplace_back(new_entity);
	return *new_entity;
}

void entity_manager::update(const float delta_time)
{
	for (size_t i{}; i < entities_.size(); i++)
	{
		if (!entities_[i]->is_active())
		{
			entities_.erase(entities_.begin() + i);
		}
		else
		{
			entities_[i]->update(delta_time);
		}
	}
}

void entity_manager::render() const
{
	for (size_t layer_number{}; layer_number < num_layers; layer_number++)
	{
		for (auto& entity: get_entities_by_layer(static_cast<layer_type>(layer_number)))
		{
			entity->render();
		}
	}
}

void entity_manager::clean_up()
{
	for (auto& e : entities_)
	{
		if (!e->is_active())
			entities_.erase(entities_.begin(), entities_.end());
	}
}

bool entity_manager::has_no_entities() const
{
	return entities_.empty();
}

std::vector<std::shared_ptr<entity>> entity_manager::get_entities() const
{
	return entities_;
}

std::shared_ptr<entity> entity_manager::get_entity_by_name(const std::string& entity_name)
{
	for (auto& entity : entities_)
	{
		if (entity->name == entity_name)
		{
			return entity;
		}
	}

	return nullptr;
}

std::vector<std::shared_ptr<entity>> entity_manager::get_entities_by_layer(const layer_type layer) const
{
	std::vector<std::shared_ptr<entity>> selected_entities;
	for (auto& entity: entities_)
	{
		if (entity->layer == layer)
		{
			selected_entities.emplace_back(entity);
		}
	}
	return selected_entities;
}
