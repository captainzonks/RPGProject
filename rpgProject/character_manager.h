#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "constants.h"

class character;

class character_manager
{
public:

	void add_character(const std::shared_ptr<character>& character);
	
	// all characters
	void display_all_characters() const;
	[[nodiscard]] int total_characters() const;

	// all Player
	void display_all_players() const;
	[[nodiscard]] int total_players() const;

	// all NPC
	void display_all_npcs() const;
	[[nodiscard]] int total_npcs() const;

	void update(float delta_time);
	void draw() const;
	void clean_up();

	[[nodiscard]] bool has_no_characters() const;
	[[nodiscard]] std::vector<std::shared_ptr<character>> get_characters() const;
	[[nodiscard]] std::shared_ptr<character> get_character_by_name(std::string& character_name) const;
	[[nodiscard]] std::vector<std::shared_ptr<character>> get_characters_by_layer(layer_type layer) const;
	
	static character_manager* instance()
	{
		return &character_manager_instance_;
	}
	
protected:
	character_manager() = default;
	static character_manager character_manager_instance_;

private:
	std::vector<std::shared_ptr<character>> characters_ {};
};

#endif
