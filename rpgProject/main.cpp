// MAIN

#include <iostream>
#include <time.h>

#include "Actor.h"
#include "Human.h"
#include "Elf.h"
#include "Dwarf.h"
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
    
    cout << "Inventory Capacity: " << player->myInventory.getCapacity() << endl;
    cout << player->getName() << "'s Money" << endl;
    player->myCurrency.displayMoney();

    
    player->myInventory.addToInventory(narrator.makeASword());
    player->myInventory.displayInventory();

    delete player;

    return 0;
}
