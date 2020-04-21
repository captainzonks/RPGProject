#ifndef CHARACTER_H
#define CHARACTER_H

#include "attributes.h"
#include "inventory.h"
#include "currency.h"
#include "character_job.h"

class character
{
public:
	character(const character& other) = default;

	character(character&& other) noexcept
		: is_alive_(other.is_alive_),
		  my_attributes_(other.my_attributes_),
		  my_inventory_(other.my_inventory_),
		  my_currency_(other.my_currency_),
		  my_job_(other.my_job_)
	{
	}

	character& operator=(const character& other)
	{
		if (this == &other)
			return *this;
		is_alive_ = other.is_alive_;
		my_attributes_ = other.my_attributes_;
		my_inventory_ = other.my_inventory_;
		my_currency_ = other.my_currency_;
		my_job_ = other.my_job_;
		return *this;
	}

	character& operator=(character&& other) noexcept
	{
		if (this == &other)
			return *this;
		is_alive_ = other.is_alive_;
		my_attributes_ = other.my_attributes_;
		my_inventory_ = other.my_inventory_;
		my_currency_ = other.my_currency_;
		my_job_ = other.my_job_;
		return *this;
	}

	explicit character(attributes* new_attributes, currency* new_currency, character_job* new_combat_class);
	~character();

	void update() const;
	void display() const;

	[[nodiscard]] bool alive() const { return is_alive_; }
	void die() { is_alive_ = false; }
	
	[[nodiscard]] attributes& access_attributes() const { return *my_attributes_; }
	[[nodiscard]] inventory& access_inventory() const { return *my_inventory_; }
	[[nodiscard]] currency& access_currency() const { return *my_currency_; }
	[[nodiscard]] character_job& access_job() const { return *my_job_; }
	
private:
	bool is_alive_;
	attributes* my_attributes_ {};
	inventory* my_inventory_ {};
	currency* my_currency_ {};
	character_job* my_job_ {};
};

#endif