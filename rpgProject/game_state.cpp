#include "game_state.h"

#include <sol.hpp>

#include "asset_manager.h"
#include "entity.h"
#include "entity_manager.h"
#include "game_map.h"
#include "keyboard_control_component.h"
#include "sprite_component.h"
#include "transform_component.h"

game_map* map;

void game_state::load(int level_number)
{
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

	auto level_name = "Level" + std::to_string(level_number);
	lua.script_file("./assets/scripts/" + level_name + ".lua");

	/*************************************/
	/* LOADS ASSETS FROM LUA CONFIG FILE */
	/*************************************/
	sol::table level_data = lua["Level1"];
	sol::table level_assets = level_data["assets"];

	unsigned asset_index {};

	while (true)
	{
		sol::optional<sol::table> exists_asset_index_node = level_assets[asset_index];
		if (exists_asset_index_node == sol::nullopt)
		{
			break;
		}
		else
		{
			sol::table asset = level_assets[asset_index];
			std::string asset_type = asset["type"];
			if (asset_type == "texture")
			{
				std::string asset_id = asset["id"];
				std::string asset_file = asset["file"];
				asset_manager::instance()->add_texture(asset_id, asset_file.c_str());
			}
			if (asset_type == "font")
			{
				std::string asset_id = asset["id"];
				std::string asset_file = asset["file"];
				const auto font_size = asset["font_size"];
				asset_manager::instance()->add_font(asset_id, asset_file.c_str(), font_size);
			}
		}
		asset_index++;
	}

	/*************************************/
	/* LOADS MAP FROM LUA CONFIG FILE    */
	/*************************************/
	sol::table level_map = level_data["game_map"];
	std::string map_texture_id = level_map["texture_asset_id"];
	std::string map_file = level_map["file"];

	map = new game_map(
		map_texture_id,
		static_cast<int>(level_map["scale"]),
		static_cast<int>(level_map["tile_size"])
	);

	map->load_map(
		map_file,
		static_cast<int>(level_map["map_size_x"]),
		static_cast<int>(level_map["map_size_y"])
	);

	/*****************************************************/
	/* LOAD ENTITIES AND COMPONENTS FROM LUA CONFIG FILE */
	/*****************************************************/
	sol::table level_entities = level_data["entities"];
	unsigned entity_index {};
	while (true)
	{
		sol::optional<sol::table> exists_entity_index_node = level_entities[entity_index];
		if (exists_entity_index_node == sol::nullopt)
		{
			break;
		}
		else
		{
			sol::table entity = level_entities[entity_index];
			std::string entity_name = entity["name"];
			auto entity_layer_type = static_cast<layer_type>(static_cast<int>(entity["layer"]));

			// add new entity
			auto& new_entity(entity_manager::instance()->add_entity(entity_name, entity_layer_type));

			// add transform component
			sol::optional<sol::table> exists_transform_component = entity["components"]["transform"];
			if (exists_transform_component != sol::nullopt)
			{
				new_entity.add_component<transform_component>(
					static_cast<int>(entity["components"]["transform"]["position"]["x"]),
					static_cast<int>(entity["components"]["transform"]["position"]["y"]),
					static_cast<int>(entity["components"]["transform"]["velocity"]["x"]),
					static_cast<int>(entity["components"]["transform"]["velocity"]["y"]),
					static_cast<int>(entity["components"]["transform"]["width"]),
					static_cast<int>(entity["components"]["transform"]["height"]),
					static_cast<int>(entity["components"]["transform"]["scale"])
					);
			}

			// add sprite component
			sol::optional<sol::table> exists_sprite_component = entity["components"]["sprite"];
			if (exists_sprite_component != sol::nullopt)
			{
				std::string texture_id = entity["components"]["sprite"]["texture_asset_id"];
				bool is_animated = entity["components"]["sprite"]["animated"];
				if (is_animated)
				{
					new_entity.add_component<sprite_component>(
						texture_id,
						static_cast<int>(entity["components"]["sprite"]["frame_count"]),
						static_cast<int>(entity["components"]["sprite"]["animation_speed"]),
						static_cast<bool>(entity["components"]["sprite"]["has_directions"]),
						static_cast<bool>(entity["components"]["sprite"]["fixed"])
						);
				}
				else
				{
					new_entity.add_component<sprite_component>(texture_id, false);
				}
			}

			// add input control component
			sol::optional<sol::table> exists_input_component = entity["components"]["input"];
			if (exists_input_component != sol::nullopt)
			{
				sol::optional<sol::table> exists_keyboard_input_component = entity["components"]["input"]["keyboard"];
				if (exists_keyboard_input_component != sol::nullopt)
				{
					std::string up_key = entity["components"]["input"]["keyboard"]["up"];
					std::string right_key = entity["components"]["input"]["keyboard"]["right"];
					std::string down_key = entity["components"]["input"]["keyboard"]["down"];
					std::string left_key = entity["components"]["input"]["keyboard"]["left"];
					std::string interact_key = entity["components"]["input"]["keyboard"]["interact"];
					new_entity.add_component<keyboard_control_component>(up_key, right_key, down_key, left_key, interact_key);
				}
			}

			// add collider component
			sol::optional<sol::table> exists_collider_component = entity["components"]["collider"];
			// TODO: consider adding in collision
			
		}
		entity_index++;
	}

	
}
