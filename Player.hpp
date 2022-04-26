#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"


#pragma once
using namespace std;

namespace coup{
class Game;
class Player
{
public:
    Player(){};
    Player(Game &game , const string &name){};

    ~Player(){};

    void income();
    void foreign_aid();
    void coup(Player & player);
    std::string getName();
    int coins();
    void print();
    string role();
    void setRole();

private:
    std::string name;
    string playeRole;
    int coinsAmount;
    bool isPlaying;
};
}