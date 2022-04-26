#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#pragma once
using namespace std;



namespace coup{
    class Player;
    class Game
{

public:
    Game();
    void addPlayer(Player &player);
    void removePlayer(Player player);
    vector<string> players();
    void playerStatus(Player player);
    string turn();
    void winner();
    int getNumPlayers();


    private:
    vector<string*> gamePlayers;
    int numPlayers;
    bool playing;

};
}