cmake_minimum_required(VERSION 3.12)

project (RPG_Game)

file (GLOB_RECURSE RPG_Game_SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB_RECURSE RPG_Game_HEADERS CONFIGURE_DEPENDS "*.h")

set (RPG_Game_INCLUDE_DIRS "")
foreach (_headerFile ${RPG_Game_HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list (APPEND RPG_Game_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES RPG_Game_INCLUDE_DIRS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(RPG_Game ${RPG_Game_SOURCES})
target_include_directories(RPG_Game PRIVATE ${RPG_Game_INCLUDE_DIRS})
