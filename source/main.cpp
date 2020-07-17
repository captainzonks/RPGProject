// MAIN

#include "character_creator_state.h"
#include "constants.h"
#include "game.h"

int main()
{
  game game;

  // initialize
  game.init();

  game.change_state(character_creator_state::instance());

  // main loop
  while (game.is_running())
  {
    game.handle_events();
    game.update();
    game.render();
  }

  // cleanup
  game.cleanup();

  return 0;
}