// MAIN

#include <iostream>
#include <time.h>

// #include "GameEngine.h"
// #include "GameState.h"

#include "Actor.h"
#include "Human.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Narrator.h"
#include "Item.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0)); // seed the dice rolls

    Narrator narrator; // start the narrator

    narrator.startGreeting();

    Actor* player{ nullptr };

    player = narrator.characterCreator();

    player->display();
    
    cout << "Inventory Capacity: " << player->myInventory.getCapacity() << endl;
    cout << player->getName() << "'s Money" << endl;
    player->myCurrency.displayMoney();
    
    player->myInventory.addToInventory(narrator.makeAnItem(Narrator::ITEM_TYPES::SWORD));
    player->myInventory.addToInventory(narrator.makeAnItem(Narrator::ITEM_TYPES::SHIELD));
    player->myInventory.displayInventory();

    delete player;

    return 0;
}
