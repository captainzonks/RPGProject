#include "map_menu_state.h"
#include "location.h"
#include "helper_functions.h"
#include "constants.h"

map_menu_state map_menu_state::map_menu_state_;

void map_menu_state::init() {
}

void map_menu_state::cleanup() {
}

void map_menu_state::pause() {
}

void map_menu_state::resume() {
}

void map_menu_state::handle_events(game *game) {
  if (choice_ != 0) {
	switch (choice_) {
	  case 1: game->the_world.add_location(make_new_location());
		break;
	  case 2: game->the_world.print_locations();
		break;
	  case 3: game->pop_state();
		break;
	  default: break;
	}
  }
}

void map_menu_state::update(game *game) {
}

void map_menu_state::render(game *game) {
  print_menu(this->name_, options_);

  choice_ = menu_choice(options_);
}

location *map_menu_state::make_new_location() {
  coordinates coords{500, 700};
  const auto l = new location("Big House", coords);

  return l;
}
