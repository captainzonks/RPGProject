#include "tile_layer.h"

tile_layer::tile_layer(const int tile_size, const int row_count, const int column_count, tile_map tile_map, tile_set_list tile_sets)
	:	tile_size_(tile_size), row_count_(row_count), column_count_(column_count), tile_map_(std::move(tile_map)), tile_sets_(std::move(tile_sets))
{
}

void tile_layer::update(float delta_time)
{
}

void tile_layer::render()
{
}
