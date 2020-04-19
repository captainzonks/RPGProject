#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <memory>

class character;
class attributes;
class inventory;
class currency;
class combat_class;

class character_builder
{
public:
	~character_builder() = default;

	void build_attributes();
	void build_currency();
	void build_combat_class();

	static character_builder* instance() { return &character_builder_instance_; }
	
	[[nodiscard]] std::shared_ptr<character> build_character();

protected:
	character_builder() = default;
	static character_builder character_builder_instance_;
	
	attributes* built_attributes_ {};
	currency* built_currency_ {};
	combat_class* built_combat_class_ {};
	std::shared_ptr<character> result_ {};
};

#endif