#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <vector>

#include "component.h"
#include "item.h"

class inventory_component final
	: public component
{
public:
	inventory_component() = default;
	inventory_component(const inventory_component &other) = delete;

	inventory_component(inventory_component &&other) noexcept
		: component(other),
		  the_inventory_(std::move(other.the_inventory_)),
		  capacity_(other.capacity_),
		  armor_bonus_(other.armor_bonus_),
		  ammunition_(other.ammunition_),
		  helmet_slot_(std::move(other.helmet_slot_)),
		  chest_slot_(std::move(other.chest_slot_)),
		  legs_slot_(std::move(other.legs_slot_)),
		  hands_slot_(std::move(other.hands_slot_)),
		  feet_slot_(std::move(other.feet_slot_)),
		  main_hand_slot_(std::move(other.main_hand_slot_)),
		  off_hand_slot_(std::move(other.off_hand_slot_))
	{
	}

	inventory_component &operator=(const inventory_component &other) = delete;

	inventory_component &operator=(inventory_component &&other) noexcept
	{
		if (this == &other)
			return *this;
		component::operator=(other);
		the_inventory_ = std::move(other.the_inventory_);
		capacity_ = other.capacity_;
		armor_bonus_ = other.armor_bonus_;
		ammunition_ = other.ammunition_;
		helmet_slot_ = std::move(other.helmet_slot_);
		chest_slot_ = std::move(other.chest_slot_);
		legs_slot_ = std::move(other.legs_slot_);
		hands_slot_ = std::move(other.hands_slot_);
		feet_slot_ = std::move(other.feet_slot_);
		main_hand_slot_ = std::move(other.main_hand_slot_);
		off_hand_slot_ = std::move(other.off_hand_slot_);
		return *this;
	}

	~inventory_component();

	void initialize() override {}
	void update() override;
	void render() override {}

	void update_armor_bonus();

	void set_capacity(int new_capacity);
	[[nodiscard]] unsigned int get_capacity() const;
	[[nodiscard]] int get_armor_bonus() const { return armor_bonus_; }
	[[nodiscard]] int total_items_in_inventory() const;

	// inventory_component functions
	bool add_to_inventory(std::unique_ptr<item> item);
	void remove_from_inventory(unsigned item_identifier);
	void display_inventory() const;
	void display_equipped() const;
	std::unique_ptr<item> get_item(unsigned item_identifier);

	// ammunition
	[[nodiscard]] int return_ammo() const;
	void subtract_ammo();
	void add_ammo(int amount);

	// equipment functions
	void equip(std::unique_ptr<item> item);
	void unequip(std::unique_ptr<item> item);
	static bool ask_to_swap(item &new_item, item &old_item);

private:
	std::vector<std::unique_ptr<item>> the_inventory_{};
	unsigned int capacity_{10};
	int armor_bonus_{};
	int ammunition_{};

	// equipped armor
	std::unique_ptr<item> helmet_slot_;
	std::unique_ptr<item> chest_slot_;
	std::unique_ptr<item> legs_slot_;
	std::unique_ptr<item> hands_slot_;
	std::unique_ptr<item> feet_slot_;

	// equipped hands
	std::unique_ptr<item> main_hand_slot_;
	std::unique_ptr<item> off_hand_slot_;
};

#endif