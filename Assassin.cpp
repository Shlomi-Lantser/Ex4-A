#include <iostream>
#include <string>
#include "Assassin.hpp"
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    Assassin::Assassin(){}
    Assassin::Assassin(Game game , string name){}
    Assassin::~Assassin(){}
    void Assassin::income(){}
    void Assassin::foreign_aid(){}
    void Assassin::role(){}
    void Assassin::coup(Player & player){} //Can kill the target player for 3 coins instead of 7.
    void Assassin::print(){}
}