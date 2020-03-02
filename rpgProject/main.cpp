// MAIN

#include <time.h>

#include "Game.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0)); // seed the dice rolls

    Game game;
    game.GameLoop();

    
    //cout << "Inventory Capacity: " << player->myInventory.getCapacity() << endl;
    //cout << player->getName() << "'s Money" << endl;
    //player->myCurrency.displayMoney();

    //player->myInventory.addToInventory(narrator.makeAnItem(Narrator::ITEM_TYPES::SWORD));
    //player->myInventory.displayInventory();

    return 0;
}
