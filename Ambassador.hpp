#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{

class Ambassador : public Player
{
public: 
    Ambassador(){};
    Ambassador(Game game , string name){};
    ~Ambassador(){};
    void role();
    void coup(Player & player);
    void print();
    void transfer(Player & source ,Player & target);
    void block();

    private:
    string playerRole;
};
}