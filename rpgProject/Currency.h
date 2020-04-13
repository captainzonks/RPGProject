#ifndef CURRENCY_H
#define CURRENCY_H

class currency
{
public:
	currency(const currency& other) = default;

	currency(currency&& other) noexcept
		: copper_(other.copper_)
	{
	}

	currency& operator=(const currency& other) = default;

	currency& operator=(currency&& other) noexcept
	{
		if (this == &other)
			return *this;
		copper_ = other.copper_;
		return *this;
	}

	currency() = default;

    ~currency() = default;

    // getters
    unsigned get_gold() const, get_silver() const, get_copper() const;
    void display_money() const;

    // add or subtract
    void add_money(unsigned copper);
    void subtract_money(unsigned copper);

private:
    unsigned copper_{};

};

#endif