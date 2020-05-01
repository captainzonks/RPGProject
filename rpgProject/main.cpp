// MAIN

#include "game.h"
#include "constants.h"
#include "character_creator_state.h"

int main(int argc, char* args[])
{
    game game;

    // initialize
    game.initialize(window_width, window_height);

    // start the entity creator
    game.change_state(character_creator_state::instance());

    // main loop
    while (game.is_running())
    {
        game.handle_events();
        game.update();
        game.draw();
    }

    // cleanup
    game.cleanup();

    return 0;
}
