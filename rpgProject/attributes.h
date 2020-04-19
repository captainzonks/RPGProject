#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include <string>

#include "constants.h"

class attributes
{
public:
	attributes(const attributes& other) = default;

	attributes(attributes&& other) noexcept
		: label_(std::move(other.label_)),
		  name_(std::move(other.name_)),
		  race_enum_(other.race_enum_),
		  race_string_(std::move(other.race_string_)),
		  current_health_(other.current_health_),
		  max_health_(other.max_health_),
		  current_mana_(other.current_mana_),
		  max_mana_(other.max_mana_),
		  current_exp_(other.current_exp_),
		  strength_(other.strength_),
		  dexterity_(other.dexterity_),
		  constitution_(other.constitution_),
		  intelligence_(other.intelligence_),
		  wisdom_(other.wisdom_),
		  charisma_(other.charisma_)
	{
	}

	attributes& operator=(const attributes& other)
	{
		if (this == &other)
			return *this;
		label_ = other.label_;
		name_ = other.name_;
		race_enum_ = other.race_enum_;
		race_string_ = other.race_string_;
		current_health_ = other.current_health_;
		max_health_ = other.max_health_;
		current_mana_ = other.current_mana_;
		max_mana_ = other.max_mana_;
		current_exp_ = other.current_exp_;
		strength_ = other.strength_;
		dexterity_ = other.dexterity_;
		constitution_ = other.constitution_;
		intelligence_ = other.intelligence_;
		wisdom_ = other.wisdom_;
		charisma_ = other.charisma_;
		return *this;
	}

	attributes& operator=(attributes&& other) noexcept
	{
		if (this == &other)
			return *this;
		label_ = std::move(other.label_);
		name_ = std::move(other.name_);
		race_enum_ = other.race_enum_;
		race_string_ = std::move(other.race_string_);
		current_health_ = other.current_health_;
		max_health_ = other.max_health_;
		current_mana_ = other.current_mana_;
		max_mana_ = other.max_mana_;
		current_exp_ = other.current_exp_;
		strength_ = other.strength_;
		dexterity_ = other.dexterity_;
		constitution_ = other.constitution_;
		intelligence_ = other.intelligence_;
		wisdom_ = other.wisdom_;
		charisma_ = other.charisma_;
		return *this;
	}

	attributes() = default;
	explicit attributes(std::string label, std::string name, race_options race, const int& strength, const int& dexterity, const int& constitution, const int& intelligence, const int& wisdom, const int& charisma);
	~attributes() = default;


	[[nodiscard]] std::string get_label() const { return label_; }
	[[nodiscard]] std::string get_name() const { return name_; }
	[[nodiscard]] race_options get_race_enum() const { return race_enum_; }
	[[nodiscard]] std::string get_race_string() const { return race_string_; }

	[[nodiscard]] int get_current_health() const { return current_health_; }
	[[nodiscard]] int get_max_health() const { return max_health_; }
	[[nodiscard]] int get_current_mana() const { return current_mana_; }
	[[nodiscard]] int get_max_mana() const { return max_mana_; }
	[[nodiscard]] int get_current_exp() const { return current_exp_; }

	[[nodiscard]] int get_strength() const { return strength_; }
	[[nodiscard]] int get_strength_mod() const { return (strength_ - 10) / 2; }
	[[nodiscard]] int get_dexterity() const { return dexterity_; }
	[[nodiscard]] int get_dexterity_mod() const { return (dexterity_ - 10) / 2; }
	[[nodiscard]] int get_constitution() const { return constitution_; }
	[[nodiscard]] int get_constitution_mod() const { return (constitution_ - 10) / 2; }
	[[nodiscard]] int get_intelligence() const { return intelligence_; }
	[[nodiscard]] int get_intelligence_mod() const { return (intelligence_ - 10) / 2; }
	[[nodiscard]] int get_wisdom() const { return wisdom_; }
	[[nodiscard]] int get_wisdom_mod() const { return (wisdom_ - 10) / 2; }
	[[nodiscard]] int get_charisma() const { return charisma_; }
	[[nodiscard]] int get_charisma_mod() const { return (charisma_ - 10) / 2; }
	
private:
	std::string label_, name_;
	race_options race_enum_ {race_options::none};
	std::string race_string_;
	int current_health_{}, max_health_{}, current_mana_{}, max_mana_{}, current_exp_{};

	int strength_{}, dexterity_{}, constitution_{}, intelligence_{}, wisdom_{}, charisma_{};
};

#endif