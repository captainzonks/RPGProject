#ifndef COMBAT_CLASS_H
#define COMBAT_CLASS_H

#include <ostream>
#include <vector>

#include "constants.h"

class class_features;
class fighter_features;
class wizard_features;
class rogue_features;

class combat_class final
{
public:
	combat_class() = default;
	explicit combat_class(combat_class_enum class_choice);
	~combat_class();
	
	combat_class(const combat_class& other) = default;

	combat_class(combat_class&& other) noexcept
		: my_class_(std::move(other.my_class_)),
		  my_fighter_features_(other.my_fighter_features_),
		  my_wizard_features_(other.my_wizard_features_),
		  my_rogue_features_(other.my_rogue_features_)
	{
	}

	combat_class& operator=(const combat_class& other)
	{
		if (this == &other)
			return *this;
		my_class_ = other.my_class_;
		my_fighter_features_ = other.my_fighter_features_;
		my_wizard_features_ = other.my_wizard_features_;
		my_rogue_features_ = other.my_rogue_features_;
		return *this;
	}

	combat_class& operator=(combat_class&& other) noexcept
	{
		if (this == &other)
			return *this;
		my_class_ = std::move(other.my_class_);
		my_fighter_features_ = other.my_fighter_features_;
		my_wizard_features_ = other.my_wizard_features_;
		my_rogue_features_ = other.my_rogue_features_;
		return *this;
	}
	
	void set_features(combat_class_enum class_choice);

	[[nodiscard]] bool is_fighter() const { return my_fighter_features_ != nullptr; }
	[[nodiscard]] bool is_wizard() const { return my_wizard_features_ != nullptr; }
	[[nodiscard]] bool is_rogue() const { return my_rogue_features_ != nullptr; }
	
	[[nodiscard]] fighter_features* access_fighter_features() const;
	[[nodiscard]] wizard_features* access_wizard_features() const;
	[[nodiscard]] rogue_features* access_rogue_features() const;
	
	void build_class(combat_class_enum class_choice);
	void display_class() const;
	std::vector<combat_class_enum>& get_my_class() { return my_class_; }
	
	void attack();
	
private:
	// class storage
	std::vector<combat_class_enum> my_class_ {};

	// class pointers
	fighter_features* my_fighter_features_ {};
	wizard_features* my_wizard_features_ {};
	rogue_features* my_rogue_features_ {};
};

#endif