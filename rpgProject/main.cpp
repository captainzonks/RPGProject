// MAIN

#include "game.h"
#include "character_creator_state.h"

int main()
{
    game game;

    // initialize
    game.initialize();

    // start the character creator
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
