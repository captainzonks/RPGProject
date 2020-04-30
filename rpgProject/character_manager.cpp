#include "character_manager.h"
#include "character.h"

character_manager character_manager::character_manager_instance_;

void character_manager::add_character(const std::shared_ptr<character>& character)
{
	characters_.push_back(character);
}

void character_manager::display_all_characters() const
{
	for (auto& c : characters_)
	{
		std::cout << std::endl;
		c->display();
		std::cout << std::endl;
	}
}

int character_manager::total_characters() const
{
	return characters_.capacity();
}

void character_manager::display_all_players() const
{
	for (auto& c : characters_)
		if (c->get_component<attributes_component>()->get_label() == "Player")
			c->display();
}

int character_manager::total_players() const
{
	int sum {};
	for (auto& c : characters_)
		if (c->get_component<attributes_component>()->get_label() == "Player")
			sum++;

	return sum;
}

void character_manager::display_all_npcs() const
{
	for (auto& c : characters_)
		if (c->get_component<attributes_component>()->get_label() == "NPC")
			c->display();
}

int character_manager::total_npcs() const
{
	int sum {};
	for (auto& c : characters_)
		if (c->get_component<attributes_component>()->get_label() == "NPC")
			sum++;

	return sum;
}

void character_manager::update(const float delta_time)
{
	for (auto& c : characters_)
		c->update(delta_time);

	clean_up();
}

void character_manager::draw() const
{
	for (int layer_number {}; layer_number < num_layers; layer_number++)
	{
		for (auto& character: get_characters_by_layer(static_cast<layer_type>(layer_number)))
		{
			character->draw();
		}
	}
}

void character_manager::clean_up()
{
	for (auto& c : characters_)
	{
		if (!c->alive())
			characters_.erase(characters_.begin(), characters_.end());
	}
}

bool character_manager::has_no_characters() const
{
	return characters_.empty();
}

std::vector<std::shared_ptr<character>> character_manager::get_characters() const
{
	return characters_;
}

std::shared_ptr<character> character_manager::get_character_by_name(std::string& character_name) const
{
	for (auto character : characters_)
	{
		if (character->get_component<attributes_component>()->get_name() == character_name)
		{
			return character;
		}
	}

	return nullptr;
}

std::vector<std::shared_ptr<character>> character_manager::get_characters_by_layer(const layer_type layer) const
{
	std::vector<std::shared_ptr<character>> selected_characters;
	for (auto& character: characters_)
	{
		if (character->get_component<attributes_component>()->get_layer() == layer)
		{
			selected_characters.emplace_back(character);
		}
	}
	return selected_characters;
}
