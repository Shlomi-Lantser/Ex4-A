#include <iostream>
#include <string>
#include "Player.hpp"


namespace coup{

class Contessa : public Player
{
    public:
        Contessa(){};
        Contessa(Game game , string name){};
        ~Contessa(){};
        void role();
        void coup(Player & player);
        void print();
        string getRole();
        void setRole();
        void block(Player & player); //Assasination block.
        void steal(Player* target);

    private:
        string playerRole;
};
}