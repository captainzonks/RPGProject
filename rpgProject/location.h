#ifndef LOCATION_H
#define LOCATION_H
#include <vector>

class location
{
public:

	explicit location(std::vector<int> coordinates)
		: coordinates_(std::move(coordinates))
	{
	}

	[[nodiscard]] std::vector<int> get_coordinates() const { return coordinates_; }
	
private:

	std::vector<int> coordinates_ {};
};

#endif