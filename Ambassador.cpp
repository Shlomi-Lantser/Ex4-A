#include <iostream>
#include <string>
#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    void Ambassador::role(){};
    void Ambassador::coup(Player & player){};
    void Ambassador::print(){};
    void Ambassador::transfer(Player & source ,Player & target){};
    void Ambassador::block(){};
}