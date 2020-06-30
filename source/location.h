#ifndef LOCATION_H
#define LOCATION_H
#include <memory>
#include <string>
#include <vector>

#include "entity.h"

class location
{
public:

	explicit location(std::string name, std::vector<double> coordinates)
		: name_(std::move(name)), coordinates_(std::move(coordinates))
	{
	}

	void update();

	void add_owners(entity& owner);
	void add_visitors(entity& visitor);

	void remove_owners(entity& not_owner);
	void remove_visitors(entity& not_visitor);
	
	[[nodiscard]] std::string get_name() const { return name_; }
	[[nodiscard]] std::vector<double> get_coordinates() const { return coordinates_; }

	[[nodiscard]] std::vector<entity> get_owners() const { return owners_; }
	[[nodiscard]] std::vector<entity> get_visitors() const { return visitors_; }
	
private:
	std::string name_ {};
	std::vector<double> coordinates_ {};

	std::vector<entity> owners_ {};
	std::vector<entity> visitors_ {};
};

#endif