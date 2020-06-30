#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <memory>
#include <string>

#include "constants.h"

class entity;
class attributes_component;
class inventory_component;
class currency_component;
class job_component;

class character_builder
{
public:
	~character_builder() = default;

	void ask_for_race_and_name() const;
	void build_attributes(const std::string& name, const std::string& label, race_options race) const;
	void build_currency() const;
	void build_inventory() const;
	void build_transform() const;
	void ask_for_job() const;
	void build_job(job_labels choice) const;

	static character_builder* instance() { return &character_builder_instance_; }

	[[nodiscard]] std::shared_ptr<entity> build_player();
	[[nodiscard]] std::shared_ptr<entity> build_character();

protected:
	character_builder() = default;
	static character_builder character_builder_instance_;
	
	std::shared_ptr<entity> result_ {};
};

#endif