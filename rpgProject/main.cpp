// MAIN

#include <iostream>
#include <time.h>

#include "Actor.h"
#include "Human.h"
#include "Narrator.h"

using namespace std;

int main()
{

    srand((unsigned int)time(0)); // seed the dice rolls
    Narrator narrator{}; // start the narrator

    narrator.startGreeting();

    Actor* player{ nullptr };

    player = narrator.characterCreator();

    player->display();

    // narrator.encounter(&player, &enemy);
    // enemy.display();

    // narrator.buySomething(player);


    return 0;
}
