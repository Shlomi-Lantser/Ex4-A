#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup{

class Duke : public Player{
public:
    Duke();
    Duke(Game game , string name);
    ~Duke();
    void income(); //Can take 1 coins from the treasury.
    void tax(); //Can take 2 coins from the treasury.
    void foreign_aid(); //Double the coins of the target player.
    string role();
    void coup(Player & player);
    void block(Player & player);
    void print();

    private:
    string playerRole;
};
}