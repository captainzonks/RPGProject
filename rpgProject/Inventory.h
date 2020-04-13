#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <string>
#include <vector>

class item;

class inventory
{
public:
	inventory(const inventory& other) = default;

	inventory(inventory&& other) noexcept
		: the_inventory_(std::move(other.the_inventory_)),
		  capacity_(other.capacity_),
		  ammunition_(other.ammunition_)
	{
	}

	inventory& operator=(const inventory& other)
	{
		if (this == &other)
			return *this;
		the_inventory_ = other.the_inventory_;
		capacity_ = other.capacity_;
		ammunition_ = other.ammunition_;
		return *this;
	}

	inventory& operator=(inventory&& other) noexcept
	{
		if (this == &other)
			return *this;
		the_inventory_ = std::move(other.the_inventory_);
		capacity_ = other.capacity_;
		ammunition_ = other.ammunition_;
		return *this;
	}

	// constructor
	inventory() = default;

	// destructor
	~inventory();

	void set_capacity(int new_capacity);
	unsigned int get_capacity() const;
	int total_items_in_inventory() const;

	// inventory functions
	void add_to_inventory(std::unique_ptr<item> item);
	void remove_from_inventory(const std::string& item_name);
	void display_inventory() const;
	std::unique_ptr<item> get_item(const std::string& item_name);
	
	// ammunition_
	int return_ammo() const;
	void subtract_ammo();
	void add_ammo(int amount);

private:

	std::vector<std::unique_ptr<item>> the_inventory_{};
	unsigned int capacity_{};
	int ammunition_{};

};

#endif
