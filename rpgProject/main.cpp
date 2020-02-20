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
    cout << "Gold : " << player->myCurrency.getGold() << endl;
    cout << "Silver : " << player->myCurrency.getSilver() << endl;
    cout << "Copper : " << player->myCurrency.getCopper() << endl;

    player->myInventory.getASword();

    delete player;

    return 0;
}
