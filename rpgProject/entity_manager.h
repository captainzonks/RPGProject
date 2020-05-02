#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "constants.h"

class entity;

class entity_manager
{
public:

	entity& add_entity(std::string entity_name, layer_type layer);

	void update(float delta_time);
	void render() const;
	void clean_up();

	[[nodiscard]] bool has_no_entities() const;
	[[nodiscard]] std::vector<std::shared_ptr<entity>> get_entities() const;
	[[nodiscard]] std::shared_ptr<entity> get_entity_by_name(const std::string& entity_name);
	[[nodiscard]] std::vector<std::shared_ptr<entity>> get_entities_by_layer(layer_type layer) const;
	[[nodiscard]] unsigned get_entity_count() const { return entities_.size(); }
	
	static entity_manager* instance()
	{
		return &entity_manager_instance_;
	}
	
protected:
	entity_manager() = default;
	static entity_manager entity_manager_instance_;

private:
	std::vector<std::shared_ptr<entity>> entities_ {};
};

#endif
