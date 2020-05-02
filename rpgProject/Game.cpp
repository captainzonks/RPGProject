#include "game.h"

#include <ctime>
#include <iostream>
#include <sol.hpp>

#include "game_state.h"
#include "constants.h"
#include "asset_manager.h"
#include "collider_component.h"
#include "entity.h"
#include "entity_manager.h"
#include "game_map.h"
#include "keyboard_control_component.h"
#include "projectile_emitter_component.h"
#include "transform_component.h"

game_map* map;
//SDL_Texture* player_tex;
//SDL_Rect src_r, dest_r;

void game::initialize(const int width, const int height)
{
	srand(static_cast<unsigned>(time(nullptr))); // seed the dice rolls

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error initializing SDL." << std::endl;
		return;
	}

	if (TTF_Init() != 0)
	{
		std::cerr << "Error initializing SDL TTF." << std::endl;
		return;
	}

	window_ = SDL_CreateWindow(
		nullptr, 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_BORDERLESS
	);

	if (!window_)
	{
		std::cerr << "Error creating SDL window." << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window_, -1, 0);

	if (!renderer)
	{
		std::cerr << "Error creating SDL renderer." << std::endl;
		return;
	}
	
	running_ = true;

	load_files(1);

	//auto* tmp_surface = IMG_Load("./assets/images/player_character/ash-facing-front.png");
	//player_tex = SDL_CreateTextureFromSurface(renderer, tmp_surface);
	//SDL_FreeSurface(tmp_surface);
}

void game::cleanup()
{
	// cleanup all the states_
	while (!states_.empty())
	{
		states_.back()->cleanup();
		states_.pop_back();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

void game::change_state(game_state* state)
{
	// cleanup the current state
	if (!states_.empty())
	{
		states_.back()->cleanup();
		states_.pop_back();
	}

	// store and init the new state
	states_.push_back(state);
	states_.back()->init();
}

void game::push_state(game_state* state)
{
	// pause current state
	if (!states_.empty())
	{
		states_.back()->pause();
	}

	// store and init the new state
	states_.push_back(state);
	states_.back()->init();
}

void game::pop_state()
{
	// cleanup the current state
	if (!states_.empty())
	{
		states_.back()->cleanup();
		states_.pop_back();
	}

	// resume previous state
	if (!states_.empty())
	{
		states_.back()->resume();
	}
}

void game::handle_events()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		running_ = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			running_ = false;
	default:
		break;
	}
	
	// let the state handle events
	//states_.back()->handle_events(this);

}

void game::update()
{
	// wait until 16ms has ellapsed since the last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_last_frame_ + frame_target_time));

	// delta time is the difference in ticks from last frame converted to seconds
	auto delta_time = SDL_GetTicks() - static_cast<float>(ticks_last_frame_) / 1000.0f;

	// clamp delta time to a max value
	delta_time = delta_time > 0.05 ? 0.05f : delta_time;

	// sets the new ticks for the current frame to be used in the next pass
	ticks_last_frame_ = SDL_GetTicks();
	
	entity_manager::instance()->update(delta_time);
	
	//handle_camera_movement();

	//states_.back()->update(this);
	
}

void game::render()
{
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	
	SDL_RenderClear(renderer);

	if (entity_manager::instance()->has_no_entities())
		return;

	entity_manager::instance()->render();
	
	//states_.back()->render(this);

	SDL_RenderPresent(renderer);
}

void game::handle_camera_movement() const
{
	if (player)
	{
		const auto player_transform = player->get_component<transform_component>();

		camera.x = player_transform->position.x - (window_width / 2);
		camera.y = player_transform->position.y - (window_height / 2);

		camera.x = camera.x < 0 ? 0 : camera.x;
		camera.y = camera.y < 0 ? 0 : camera.y;
		camera.x = camera.x > camera.w ? camera.w : camera.x;
		camera.y = camera.y > camera.h ? camera.h : camera.y;
	}
}

void game::load_files(int level_number)
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
	sol::table level_map = level_data["map"];
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
			sol::table entity_t = level_entities[entity_index];
			std::string entity_name = entity_t["name"];
			auto entity_layer_type = static_cast<layer_type>(static_cast<int>(entity_t["layer"]));

			// add new entity
			auto& new_entity(entity_manager::instance()->add_entity(entity_name, entity_layer_type));

			// add transform component
			sol::optional<sol::table> exists_transform_component = entity_t["components"]["transform"];
			if (exists_transform_component != sol::nullopt)
			{
				new_entity.add_component<transform_component>(
					static_cast<int>(entity_t["components"]["transform"]["position"]["x"]),
					static_cast<int>(entity_t["components"]["transform"]["position"]["y"]),
					static_cast<int>(entity_t["components"]["transform"]["velocity"]["x"]),
					static_cast<int>(entity_t["components"]["transform"]["velocity"]["y"]),
					static_cast<int>(entity_t["components"]["transform"]["width"]),
					static_cast<int>(entity_t["components"]["transform"]["height"]),
					static_cast<int>(entity_t["components"]["transform"]["scale"])
					);
			}

			// add sprite component
			sol::optional<sol::table> exists_sprite_component = entity_t["components"]["sprite"];
			if (exists_sprite_component != sol::nullopt)
			{
				std::string texture_id = entity_t["components"]["sprite"]["texture_asset_id"];
				bool is_animated = entity_t["components"]["sprite"]["animated"];
				if (is_animated)
				{
					new_entity.add_component<sprite_component>(
						texture_id,
						static_cast<int>(entity_t["components"]["sprite"]["frame_count"]),
						static_cast<int>(entity_t["components"]["sprite"]["animation_speed"]),
						static_cast<bool>(entity_t["components"]["sprite"]["has_directions"]),
						static_cast<bool>(entity_t["components"]["sprite"]["fixed"])
						);
				}
				else
				{
					new_entity.add_component<sprite_component>(texture_id, false);
				}
			}

			// add input control component
			sol::optional<sol::table> exists_input_component = entity_t["components"]["input"];
			if (exists_input_component != sol::nullopt)
			{
				sol::optional<sol::table> exists_keyboard_input_component = entity_t["components"]["input"]["keyboard"];
				if (exists_keyboard_input_component != sol::nullopt)
				{
					std::string up_key = entity_t["components"]["input"]["keyboard"]["up"];
					std::string right_key = entity_t["components"]["input"]["keyboard"]["right"];
					std::string down_key = entity_t["components"]["input"]["keyboard"]["down"];
					std::string left_key = entity_t["components"]["input"]["keyboard"]["left"];
					std::string interact_key = entity_t["components"]["input"]["keyboard"]["interact"];
					new_entity.add_component<keyboard_control_component>(up_key, right_key, down_key, left_key, interact_key);
				}
			}

			// add collider component
			sol::optional<sol::table> exists_collider_component = entity_t["components"]["collider"];
			if (exists_collider_component != sol::nullopt)
			{
				std::string collider_tag = entity_t["components"]["collider"]["tag"];
				new_entity.add_component<collider_component>(
					collider_tag,
					static_cast<int>(entity_t["components"]["transform"]["position"]["x"]),
					static_cast<int>(entity_t["components"]["transform"]["position"]["y"]),
					static_cast<int>(entity_t["components"]["transform"]["width"]),
					static_cast<int>(entity_t["components"]["transform"]["height"])
					);
			}

			// add projectile emitter component
			sol::optional<sol::table> exists_projectile_emitter_component = entity_t["components"]["projectile_emitter"];
			if (exists_projectile_emitter_component != sol::nullopt)
			{
				int parent_entity_x_pos = entity_t["components"]["transform"]["position"]["x"];
				int parent_entity_y_pos = entity_t["components"]["transform"]["position"]["y"];
				int parent_entity_width = entity_t["components"]["transform"]["width"];
				int parent_entity_height = entity_t["components"]["transform"]["height"];
				int projectile_width = entity_t["components"]["projectile_emitter"]["width"];
				int projectile_height = entity_t["components"]["projectile_emitter"]["height"];
				int projectile_speed = entity_t["components"]["projectile_emitter"]["speed"];
				int projectile_range = entity_t["components"]["projectile_emitter"]["range"];
				int projectile_angle = entity_t["components"]["projectile_emitter"]["angle"];
				bool projectile_should_loop = entity_t["components"]["projectile_emitter"]["should_loop"];
				std::string texture_asset_id = entity_t["components"]["projectile_emitter"]["texture_asset_id"];
				auto& projectile(entity_manager::instance()->add_entity("projectile", layer_type::projectile_layer));
				projectile.add_component<transform_component>(
					parent_entity_x_pos + parent_entity_width / 2,
					parent_entity_y_pos + parent_entity_height / 2,
					0,
					0,
					projectile_width,
					projectile_height,
					1
					);
				projectile.add_component<sprite_component>(texture_asset_id);
				projectile.add_component<projectile_emitter_component>(
					projectile_speed,
					projectile_angle,
					projectile_range,
					projectile_should_loop
					);
				projectile.add_component<collider_component>(
					"PROJECTILE",
					parent_entity_x_pos,
					parent_entity_y_pos,
					projectile_width,
					projectile_height
					);
				
			}
		}
		entity_index++;
	}

	player = entity_manager::instance()->get_entity_by_name("player");
}
