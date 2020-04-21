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
		if (c->access_attributes().get_label() == "Player")
			c->display();
}

int character_manager::total_players() const
{
	int sum {};
	for (auto& c : characters_)
		if (c->access_attributes().get_label() == "Player")
			sum++;

	return sum;
}

void character_manager::display_all_npcs() const
{
	for (auto& c : characters_)
		if (c->access_attributes().get_label() == "NPC")
			c->display();
}

int character_manager::total_npcs() const
{
	int sum {};
	for (auto& c : characters_)
		if (c->access_attributes().get_label() == "NPC")
			sum++;

	return sum;
}

void character_manager::update()
{
	for (auto& c : characters_)
		c->update();

	clean_up();
}

void character_manager::clean_up()
{
	for (auto& c : characters_)
	{
		if (!c->alive())
			characters_.erase(characters_.begin(), characters_.end());
	}
}
