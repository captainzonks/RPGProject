#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <memory>

class character;

class character_builder
{
public:
	virtual void build_fighter() = 0;
	virtual void build_wizard() = 0;
	virtual void build_rogue() = 0;

	virtual ~character_builder() = default;
	
	std::shared_ptr<character> build_character() const { return result_; }

protected:
	std::shared_ptr<character> result_;
	
};

#endif