#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "constants.h"

class entity;
class game;

class entity_manager
{
public:
	void add_entity(std::shared_ptr<entity> new_entity);

	void update(game *game);
	void render(game *game) const;
	void clean_up();

	[[nodiscard]] bool has_no_entities() const;
	[[nodiscard]] std::vector<std::shared_ptr<entity>> get_entities() const;
	[[nodiscard]] std::shared_ptr<entity> get_entity_by_name(const std::string &entity_name);
	[[nodiscard]] unsigned get_entity_count() const { return entities_.size(); }

	void display_entities() const;

	static entity_manager *instance()
	{
		return &entity_manager_instance_;
	}

protected:
	entity_manager() = default;
	static entity_manager entity_manager_instance_;

private:
	std::vector<std::shared_ptr<entity>> entities_{};
};

#endif
