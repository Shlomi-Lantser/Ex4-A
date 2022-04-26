#include <iostream>
#include <string>
#include "Player.hpp"
namespace coup{

class Assassin : public Player
{
public:
    Assassin();
    Assassin(Game game , string name);
    ~Assassin();
    void income();
    void foreign_aid();
    void role();
    void coup(Player & player); //Can kill the target player for 3 coins instead of 7.
    void print();

private:
    string playerRole;
};
}