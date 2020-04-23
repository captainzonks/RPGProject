#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <vector>

class location
{
public:

	explicit location(std::string name, std::vector<double> coordinates)
		: name_(std::move(name)), coordinates_(std::move(coordinates))
	{
	}
	[[nodiscard]] std::string get_name() const { return name_; }
	[[nodiscard]] std::vector<double> get_coordinates() const { return coordinates_; }
	
private:
	std::string name_ {};
	std::vector<double> coordinates_ {};
};

#endif