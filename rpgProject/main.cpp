// MAIN

#include <iostream>
#include <memory>
#include <time.h>

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

    std::unique_ptr<Actor> player = narrator.characterCreator();

    player->display();
    
    cout << "Inventory Capacity: " << player->myInventory.getCapacity() << endl;
    cout << player->getName() << "'s Money" << endl;
    player->myCurrency.displayMoney();

    player->myInventory.addToInventory(narrator.makeAnItem(Narrator::ITEM_TYPES::SWORD));
    player->myInventory.displayInventory();

    return 0;
}
