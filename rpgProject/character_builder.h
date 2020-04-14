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
	void build_attributes() const;
	void build_inventory() const;
	void build_currency() const;
	void build_combat_class() const;

	~character_builder() = default;

	static character_builder* instance() { return &character_builder_instance_; }
	
	std::shared_ptr<character> build_character() const;

protected:
	character_builder() = default;
	static character_builder character_builder_instance_;
	std::shared_ptr<character> result_;
	
};

#endif