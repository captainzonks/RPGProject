#ifndef WORLD_MAP_H
#define WORLD_MAP_H
#include <vector>

class world_map
{
public:

	[[nodiscard]] std::vector<int> get_world_size() const { return world_size_; }

	static world_map* instance()
	{
		return &world_map_instance_;
	}
	
protected:
	world_map() = default;
	static world_map world_map_instance_;

	std::vector<int> world_size_ {100, 100, 3};
};

#endif
