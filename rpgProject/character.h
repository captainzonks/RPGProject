#ifndef CHARACTER_H
#define CHARACTER_H

class combat_class;
class attributes;
class inventory;
class currency;

class character
{
public:
	character(const character& other) = default;

	character(character&& other) noexcept
		: is_alive_(other.is_alive_),
		  my_attributes_(other.my_attributes_),
		  my_inventory_(other.my_inventory_),
		  my_currency_(other.my_currency_),
		  my_combat_class_(other.my_combat_class_)
	{
	}

	character& operator=(const character& other) = default;

	character& operator=(character&& other) noexcept
	{
		if (this == &other)
			return *this;
		is_alive_ = other.is_alive_;
		my_attributes_ = other.my_attributes_;
		my_inventory_ = other.my_inventory_;
		my_currency_ = other.my_currency_;
		my_combat_class_ = other.my_combat_class_;
		return *this;
	}

	character();
	~character();
	
	static void handle_events() {}

	static void update() {}

	bool alive() const { return is_alive_; }
	attributes* access_attributes() const { return my_attributes_; }
	inventory* access_inventory() const { return my_inventory_; }
	currency* access_currency() const { return my_currency_; }
	combat_class* access_combat_class() const { return my_combat_class_; }
	
private:
	bool is_alive_;
	attributes* my_attributes_;
	inventory* my_inventory_;
	currency* my_currency_;
	combat_class* my_combat_class_;
};

#endif