#include <iostream>
#include <string>
#include "Duke.hpp"
#include "Player.hpp"

namespace coup
{
        Duke::Duke(){};
        Duke::Duke(Game game , string name){};
        Duke::~Duke(){};
        void Duke::income(){return;}     // Can take 1 coins from the treasury.
        void Duke::tax(){return;}         // Can take 2 coins from the treasury.
        void Duke::foreign_aid(){return;} // Double the coins of the target player.
        string Duke::role(){return "Duke";}
        void Duke::coup(Player &player){return;}
        void Duke::block(Player &player){return;}
        void Duke::print(){return;}
}