#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <string>
#include <vector>
#include <tuple>

class item;

class inventory
{
public:
	inventory(const inventory& other) = delete;

	inventory(inventory&& other) noexcept
		: the_inventory_(std::move(other.the_inventory_)),
		  capacity_(other.capacity_),
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

	inventory& operator=(const inventory& other) = delete;

	inventory& operator=(inventory&& other) noexcept
	{
		if (this == &other)
			return *this;
		the_inventory_ = std::move(other.the_inventory_);
		capacity_ = other.capacity_;
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

	inventory() = default;

	~inventory();

	void set_capacity(int new_capacity);
	unsigned int get_capacity() const;
	int total_items_in_inventory() const;

	// inventory functions
	bool add_to_inventory(std::unique_ptr<item> item);
	void remove_from_inventory(unsigned item_identifier);
	void display_inventory() const;
	std::unique_ptr<item> get_item(unsigned item_identifier);
	
	// ammunition
	int return_ammo() const;
	void subtract_ammo();
	void add_ammo(int amount);

	// equipment functions
	void equip(std::unique_ptr<item> item);
	void unequip(std::unique_ptr<item> item);
	static bool ask_to_swap(item& new_item, item& old_item);

private:

	std::vector<std::unique_ptr<item>> the_inventory_{};
	unsigned int capacity_{};
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
