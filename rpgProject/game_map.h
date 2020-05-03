#ifndef MAP_H
#define MAP_H
#include <string>

class game_map
{
public:
	game_map(std::string texture_id, const int scale, const int tile_size)
		: texture_id_(std::move(texture_id)), scale_(scale), tile_size_(tile_size)
	{
		
	}
	~game_map() = default;

	void load_map(const std::string& file_path, int map_size_x, int map_size_y);
	void add_tile(int source_x, int source_y, int x, int y);

private:
	std::string texture_id_;
	int scale_;
	int tile_size_;
};

#endif