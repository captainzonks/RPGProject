// MAIN

#include "Game.h"
#include "CharacterCreatorState.h"

int main()
{
    Game game;

    // initialize
    game.Initialize();

    // start the character creator
    game.ChangeState(CharacterCreatorState::Instance());

    // main loop
    while (game.IsRunning())
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    // cleanup
    game.Cleanup();

    return 0;
}