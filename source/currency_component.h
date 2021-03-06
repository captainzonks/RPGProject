#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>

#include "component.h"

class currency_component final
	: public component
{
public:
	currency_component() = default;
	currency_component(const currency_component &other) = default;

	currency_component(currency_component &&other) noexcept
		: component(other),
		  copper_(other.copper_)
	{
	}

	currency_component &operator=(const currency_component &other)
	{
		if (this == &other)
			return *this;
		component::operator=(other);
		copper_ = other.copper_;
		return *this;
	}

	currency_component &operator=(currency_component &&other) noexcept
	{
		if (this == &other)
			return *this;
		component::operator=(other);
		copper_ = other.copper_;
		return *this;
	}

	~currency_component() { std::cout << "currency_component destructor called" << std::endl; }

	void initialize() override {}
	void update() override {}
	void render() override {}

	// getters
	[[nodiscard]] unsigned get_gold() const, get_silver() const, get_copper() const;
	void display_money() const;

	// add or subtract
	void add_money(unsigned copper);
	void subtract_money(unsigned copper);

private:
	unsigned copper_{};
};

#endif