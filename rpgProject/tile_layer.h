#ifndef TILE_LAYER_H
#define TILE_LAYER_H

#include "layer.h"

#include <string>
#include <vector>

struct tileset
{
	int first_id, last_id;
	int row_count, column_count;
	int tile_count, tile_size;
	std::string name, source;
};

using tile_set_list = std::vector<tileset>;
using tile_map = std::vector<std::vector<int> >;

class tile_layer
	:	public layer
{
public:
	tile_layer() = default;

private:
	int tile_size_ {};
	int row_count_ {}, column_count_ {};
	tile_map tile_map_;
	
};

#endif