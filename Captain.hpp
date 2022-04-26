#include <iostream>
#include <string>
#include "Player.hpp"
// #include "Duke.hpp"

namespace coup{

class Captain : public Player
{
public:
    Captain(){};
    Captain(Game game , string name){};
    ~Captain(){};
    void role();
    void coup(Player & player);
    void print();
    string getRole();
    void setRole();
    void block(Player & player);
    void steal(Player & target);

    private:
    string playerRole;
};
}