#ifndef WORLD_MAP_H
#define WORLD_MAP_H
#include <vector>

#include "location.h"

class world_map
{
public:

	[[nodiscard]] std::vector<double> get_world_size() const { return world_size_; }
	void add_place(location& new_location);
	[[nodiscard]] std::vector<location> get_places() const { return places_; }
	void print_places() const;

	static world_map* instance()
	{
		return &world_map_instance_;
	}
	
protected:
	world_map() = default;
	static world_map world_map_instance_;

	std::vector<double> world_size_ {1000, 1000, 3};

	std::vector<location> places_ {};
};

#endif
