#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "constants.h"

#include <string>
#include <vector>

class item {
 public:
  item(const item &other) = default;

  item(item &&other) noexcept
	  : item_type_(other.item_type_),
		resource_type_(other.resource_type_),
		weapon_hand_(other.weapon_hand_),
		armor_type_(other.armor_type_),
		armor_slot_(other.armor_slot_),
		name_(std::move(other.name_)),
		identifier_(other.identifier_),
		value_(other.value_),
		level_(other.level_),
		weight_(other.weight_),
		health_change_value_(other.health_change_value_),
		armor_value_(other.armor_value_),
		damage_dice_(std::move(other.damage_dice_)),
		damage_type_(other.damage_type_) {
  }

  item &operator=(const item &other) {
	if (this == &other)
	  return *this;
	item_type_ = other.item_type_;
	resource_type_ = other.resource_type_;
	weapon_hand_ = other.weapon_hand_;
	armor_type_ = other.armor_type_;
	armor_slot_ = other.armor_slot_;
	name_ = other.name_;
	identifier_ = other.identifier_;
	value_ = other.value_;
	level_ = other.level_;
	weight_ = other.weight_;
	health_change_value_ = other.health_change_value_;
	armor_value_ = other.armor_value_;
	damage_dice_ = other.damage_dice_;
	damage_type_ = other.damage_type_;
	return *this;
  }

  item &operator=(item &&other) noexcept {
	if (this == &other)
	  return *this;
	item_type_ = other.item_type_;
	resource_type_ = other.resource_type_;
	weapon_hand_ = other.weapon_hand_;
	armor_type_ = other.armor_type_;
	armor_slot_ = other.armor_slot_;
	name_ = std::move(other.name_);
	identifier_ = other.identifier_;
	value_ = other.value_;
	level_ = other.level_;
	weight_ = other.weight_;
	health_change_value_ = other.health_change_value_;
	armor_value_ = other.armor_value_;
	damage_dice_ = std::move(other.damage_dice_);
	damage_type_ = other.damage_type_;
	return *this;
  }

  item(const item_type item_type,
	   const resources resource_type,
	   const weapon_hand weapon_hand,
	   const armor_type armor_type,
	   const armor_slot armor_slot,
	   std::string name,
	   const unsigned identifier,
	   const unsigned value,
	   const unsigned level,
	   const unsigned weight,
	   const int health_change_value,
	   const int armor_value,
	   std::vector<unsigned> damage_dice,
	   const damage_type damage_type)
	  : item_type_(item_type),
		resource_type_(resource_type),
		weapon_hand_(weapon_hand),
		armor_type_(armor_type),
		armor_slot_(armor_slot),
		name_(std::move(name)),
		identifier_(identifier),
		value_(value),
		level_(level),
		weight_(weight),
		health_change_value_(health_change_value),
		armor_value_(armor_value),
		damage_dice_(std::move(damage_dice)),
		damage_type_(damage_type) {
  }

  item(const item_type item_type, const resources resource_type, std::string name)
	  : item_type_(item_type),
		resource_type_(resource_type),
		name_(std::move(name)) {
  }

  item() = default;

  ~item() { std::cout << "item destructor called" << std::endl; }

  void display();

  [[nodiscard]] item_type get_item_type() const { return item_type_; }
  [[nodiscard]] weapon_hand get_weapon_hand() const { return weapon_hand_; }
  [[nodiscard]] armor_type get_armor_type() const { return armor_type_; }
  [[nodiscard]] armor_slot get_armor_slot() const { return armor_slot_; }
  [[nodiscard]] std::string get_name() const { return name_; }
  [[nodiscard]] unsigned get_identifier() const { return identifier_; }
  [[nodiscard]] unsigned get_value() const { return value_; }
  [[nodiscard]] unsigned get_level() const { return level_; }
  [[nodiscard]] unsigned get_weight() const { return weight_; }
  [[nodiscard]] int get_health_change() const { return health_change_value_; }
  [[nodiscard]] int get_armor_value() const { return armor_value_; }
  [[nodiscard]] std::vector<unsigned> get_damage_dice() const { return damage_dice_; }
  [[nodiscard]] damage_type get_damage_type() const { return damage_type_; }

 private:

  item_type item_type_{item_type::none};
  resources resource_type_{resources::none};
  weapon_hand weapon_hand_{weapon_hand::none};
  armor_type armor_type_{armor_type::none};
  armor_slot armor_slot_{armor_slot::none};
  std::string name_{};
  unsigned identifier_{};
  unsigned value_{};
  unsigned level_{};
  unsigned weight_{};
  int health_change_value_{};
  int armor_value_{};
  std::vector<unsigned> damage_dice_{}; // ie, 1d6 or 2d8
  damage_type damage_type_{damage_type::none};

};

#endif