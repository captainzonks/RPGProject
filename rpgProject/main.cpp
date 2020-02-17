// MAIN

#include <iostream>

#include "Actor.h"
#include "Narrator.h"

using namespace std;

int main()
{
    //// Example 001
    //// basic example of Hero/Enemy creation and an attack with randomly generated damage (1 - 10)
    //Actor Player{ "Hero", 100, 100, 0 };

    //Player.display();

    //Actor Enemy{ "Enemy", 100, 100, 0 };

    //Enemy.display();

    //Player.attack(&Enemy);
    //Enemy.display();



    // Example 002
    // testing a narrator, handling character creation, temporary enemy, and dummy encounter test
    Narrator narrator;

    narrator.startGreeting();
    narrator.characterCreator();

    Actor player{};
    Actor enemy{ "Enemy" };
    player.display();
    
    narrator.encounter(&player, &enemy);

    enemy.display();



    return 0;
}
