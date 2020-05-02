----------------------------------------------------
-- Get the current time of the day from the OS
----------------------------------------------------
math.randomseed(os.time())
local current_system_hour = os.date("*t").hour
local map_texture_asset_id = "terrain-texture-day"

----------------------------------------------------
-- Use a night-map or a day-map texture (9am-9pm)
----------------------------------------------------
if current_system_hour > 9 and current_system_hour < 21 then
    map_texture_asset_id = "terrain-texture-day"
else
    map_texture_asset_id = "terrain-texture-night"
end

Level1 = {
    ----------------------------------------------------
    -- Table to define the list of assets
    ----------------------------------------------------
    assets = {
        [0] = { type="texture", id = "terrain-texture-day", file = "./assets/images/tilemaps/jungle.png"  },
        [1] = { type="texture", id = "terrain-texture-night", file = "./assets/images/tilemapes/jungle-night.png" },
        [2] = { type="texture", id = "player_texture", file = "./assets/images/player_character/ash-sprite-sheet.png" }
    },

    ----------------------------------------------------
    -- table to define the map config variables
    ----------------------------------------------------
    map = {
        texture_asset_id = map_texture_asset_id,
        file = "./assets/tilemaps/jungle.map",
        scale = 2,
        tile_size = 32,
        map_size_x = 25,
        map_size_y = 20
    },

    ----------------------------------------------------
    -- table to define entities and their components
    ----------------------------------------------------
    entities = {
        [0] = {
            name = "player",
            layer = 4,
            components = {
                transform = {
                    position = {
                        x = 240,
                        y = 106
                    },
                    velocity = {
                        x = 0,
                        y = 0
                    },
                    width = 16,
                    height = 16,
                    scale = 2,
                    rotation = 0
                },
                sprite = {
                    texture_asset_id = "player_texture",
                    animated = true,
                    frame_count = 3,
                    animation_speed = 200,
                    has_directions = true,
                    fixed = false
                },
                collider = {
                    tag = "PLAYER"        
				},
                input = {
                    keyboard = {
                        up = "w",
                        right = "d",
                        down = "s",
                        left = "a",                 
                        interact = "space"
                    }
                }
            }
        }
    }
}
