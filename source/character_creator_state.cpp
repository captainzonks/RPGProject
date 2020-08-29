#include "character_creator_state.h"
#include "character_builder.h"
#include "menu_state.h"
#include "entity_manager.h"

character_creator_state character_creator_state::character_creator_state_;

void character_creator_state::init() {
}

void character_creator_state::cleanup() {}

void character_creator_state::pause() {}

void character_creator_state::resume() {}

void character_creator_state::handle_events(game *game) {}

void character_creator_state::update(game *game) {
  game->player = character_builder::instance()->build_player();
  change_state(game, menu_state::instance());
}

void character_creator_state::render(game *game) {}
