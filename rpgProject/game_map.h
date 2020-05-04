#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include <vector>

#include "layer.h"

class game_map
{
public:
	game_map(std::string texture_id, const int scale, const int tile_size)
		: texture_id_(std::move(texture_id)), scale_(scale), tile_size_(tile_size)
	{
		
	}
	~game_map() = default;

	void render();
	void update(float delta_time);

	[[nodiscard]] std::vector<layer*> get_map_layers() const { return map_layers_; }

	void load_map(const std::string& file_path, int map_size_x, int map_size_y);
	void add_tile(int source_x, int source_y, int x, int y);

private:
	std::string texture_id_;
	int scale_;
	int tile_size_;

	std::vector<layer*> map_layers_;
};

#endif