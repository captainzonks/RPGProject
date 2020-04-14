#ifndef CHARACTER_H
#define CHARACTER_H

class combat_class;
class attributes;
class inventory;
class currency;

class character
{
public:

	character();
	~character();

	void update();

	bool alive() const { return is_alive_; }
	void die() { is_alive_ = false; }
	
	attributes& access_attributes() const { return *my_attributes_; }
	inventory& access_inventory() const { return *my_inventory_; }
	currency& access_currency() const { return *my_currency_; }
	combat_class& access_combat_class() const { return *my_combat_class_; }
	
private:
	bool is_alive_;
	attributes* my_attributes_;
	inventory* my_inventory_;
	currency* my_currency_;
	combat_class* my_combat_class_;
};

#endif