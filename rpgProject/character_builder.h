#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <memory>
#include <string>

#include "constants.h"

class character;
class attributes_component;
class inventory_component;
class currency_component;
class job_component;

class character_builder
{
public:
	~character_builder() = default;

	void ask_for_race_and_name();
	void build_attributes(const std::string& name, const std::string& label, race_options race);
	void build_currency();
	void ask_for_job();
	void build_job(job_labels choice);

	static character_builder* instance() { return &character_builder_instance_; }

	[[nodiscard]] std::shared_ptr<character> build_player();
	[[nodiscard]] std::shared_ptr<character> build_character();

protected:
	character_builder() = default;
	static character_builder character_builder_instance_;
	
	attributes_component* built_attributes_ {};
	currency_component* built_currency_ {};
	job_component* built_job_ {};
	std::shared_ptr<character> result_ {};
};

#endif