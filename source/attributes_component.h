#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include <iostream>
#include <string>

#include "component.h"
#include "constants.h"

class attributes_component final
	: public component
{
public:
	attributes_component(std::string label, std::string name, const layer_type layer, const race_options race_enum,
		const int strength, const int dexterity, const int constitution, const int intelligence, const int wisdom,
		const int charisma, const int speed)
		: label_(std::move(label)),
		  name_(std::move(name)),
		  layer_(layer),
		  race_enum_(race_enum),
		  strength_(strength),
		  dexterity_(dexterity),
		  constitution_(constitution),
		  intelligence_(intelligence),
		  wisdom_(wisdom),
		  charisma_(charisma),
		  speed_(speed)
	{
	}

	attributes_component(const attributes_component& other) = default;

	attributes_component(attributes_component&& other) noexcept
		: component(other),
		  label_(std::move(other.label_)),
		  name_(std::move(other.name_)),
		  layer_(other.layer_),
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
		  charisma_(other.charisma_),
		  speed_(other.speed_)
	{
	}

	attributes_component& operator=(const attributes_component& other)
	{
		if (this == &other)
			return *this;
		component::operator =(other);
		label_ = other.label_;
		name_ = other.name_;
		layer_ = other.layer_;
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
		speed_ = other.speed_;
		return *this;
	}

	attributes_component& operator=(attributes_component&& other) noexcept
	{
		if (this == &other)
			return *this;
		component::operator =(other);
		label_ = std::move(other.label_);
		name_ = std::move(other.name_);
		layer_ = other.layer_;
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
		speed_ = other.speed_;
		return *this;
	}

	~attributes_component()
	{
		std::cout << "attributes_component destructor called" << std::endl;
	}

	void initialize() override
	{
		
	}

	void update(float delta_time) override
	{
		
	}

	void render() override
	{
		
	}

	[[nodiscard]] std::string get_label() const { return label_; }
	[[nodiscard]] std::string get_name() const { return name_; }
	[[nodiscard]] layer_type get_layer() const { return layer_; }
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

	[[nodiscard]] int get_speed() const { return speed_; }
	
private:
	std::string label_, name_;
	layer_type layer_;
	race_options race_enum_ {race_options::none};
	std::string race_string_;
	int current_health_{}, max_health_{}, current_mana_{}, max_mana_{}, current_exp_{};

	int strength_{}, dexterity_{}, constitution_{}, intelligence_{}, wisdom_{}, charisma_{};

	int speed_ { 25 };
};

#endif