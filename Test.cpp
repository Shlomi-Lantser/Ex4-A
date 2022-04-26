#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
#include "doctest.h"
#include <string>
using namespace std;

TEST_CASE("Constructors")
{
    CHECK_NOTHROW(Game game{});
    Game game{};
    CHECK_NOTHROW(Duke duke(game, "Moshe"));
    CHECK_NOTHROW(Assassin assassin(game, "Yossi"));
    CHECK_NOTHROW(Ambassador ambassador(game, "Meirav"));
    CHECK_NOTHROW(Captain captain(game, "Reut"));
    CHECK_NOTHROW(Contessa contessa(game, "Gilad"));
}

TEST_CASE("Income")
{
    Game game{};
    Duke duke(game, "Moshe");
    Assassin assassin(game, "Yossi");
    Ambassador ambassador(game, "Meirav");
    Captain captain(game, "Reut");
    Contessa contessa(game, "Gilad");
    CHECK_NOTHROW(duke.income());
    CHECK(duke.coins() == 1);
    CHECK_NOTHROW(assassin.income());
    CHECK(assassin.coins() == 1);
    CHECK_NOTHROW(ambassador.income());
    CHECK(ambassador.coins() == 1);
    CHECK_NOTHROW(captain.income());
    CHECK(captain.coins() == 1);
    CHECK_NOTHROW(contessa.income());
    CHECK(contessa.coins() == 1);
}

TEST_CASE("Foreign Aid")
{
    Game game{};
    Duke duke(game, "Moshe");
    Assassin assassin(game, "Yossi");
    Ambassador ambassador(game, "Meirav");
    Captain captain(game, "Reut");
    Contessa contessa(game, "Gilad");
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK(duke.coins() == 2);
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK(assassin.coins() == 2);
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK(ambassador.coins() == 2);
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK(captain.coins() == 2);
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK(contessa.coins() == 2);
}

TEST_CASE("Coup")
{
    Game game{};
    Duke duke(game, "Moshe");
    Assassin assassin(game, "Yossi");
    Ambassador ambassador(game, "Meirav");
    Captain captain(game, "Reut");
    Contessa contessa(game, "Gilad");
    bool assassin_coup = false;

    for (int i = 0; i < 50; i++)
    {
        if (i % 5 == 0)
        {
            if (duke.coins() < 7)
            {
                CHECK(game.turn() == "Moshe");
                CHECK_NOTHROW(duke.income());
                CHECK_THROWS(duke.coup(assassin));
                assassin_coup = true;
            }
            else if (duke.coins() == 10)
            {
                CHECK_THROWS(duke.income());
                CHECK_THROWS(duke.foreign_aid());
            }
        }
        else if (i % 5 == 1)
        {
            if (!assassin_coup)
            {
                CHECK(game.turn() == "Yossi");
                CHECK_NOTHROW(assassin.income());
            }
            else
            {
                CHECK_THROWS(assassin.income());
                break;
            }
        }
        else if (i % 5 == 2)
        {
            CHECK(game.turn() == "Meirav");
            CHECK_NOTHROW(ambassador.income());
        }
        else if (i % 5 == 3)
        {
            CHECK(game.turn() == "Reut");
            CHECK_NOTHROW(captain.income());
        }
        else if (i % 5 == 4)
        {
            CHECK(game.turn() == "Gilad");
            CHECK_NOTHROW(contessa.income());
        }
    }
}

TEST_CASE("Assasin special")
{
    Game game{};
    Assassin assassin(game, "Yossi");
    Duke duke(game, "Moshe");
    bool duke_coup = false;
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            if (assassin.coins() <3){
            CHECK(game.turn() == "Yossi");
            CHECK_NOTHROW(assassin.income());
            }else if (assassin.coins() == 3){
                CHECK_NOTHROW(assassin.coup(duke));
                duke_coup = true;
            }
        }else if (i % 2 == 1)
        {
            if (!duke_coup){
            CHECK(game.turn() == "Moshe");
            CHECK_NOTHROW(duke.income());
            }else{
                CHECK_THROWS(duke.income());
                break;
            }
        }
    }
}

TEST_CASE("Ambassador special"){
    Game game{};
    Ambassador ambassador(game, "Meirav");
    Duke duke(game, "Moshe");
    Assassin assassin(game, "Yossi");

    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.transfer(duke, assassin));
    CHECK(assassin.coins() == 2);
}

TEST_CASE("Captain special"){
    Game game{};
    Captain captain(game, "Reut");
    Duke duke(game, "Moshe");
    Captain captain2(game, "Shlomi");
    bool duke_stolen = false;
    
    for (int i = 0; i < 12; i++)
    {
        if (i % 3 == 0)
        {
            if (captain.coins() < 3){
            CHECK(game.turn() == "Reut");
            CHECK_NOTHROW(captain.income());
            }else if (captain.coins() == 3){
                CHECK_NOTHROW(captain.steal(duke));
                duke_stolen = true;
                CHECK(duke.coins() == 0);
                CHECK(captain.coins() == 5);
            }
        }
        else if (i % 3 == 1)
        {
            CHECK(game.turn() == "Moshe");
            CHECK_NOTHROW(duke.income());

        }else if (i% 3 == 2){
            if (!duke_stolen){
            CHECK(game.turn() == "Reut");
            CHECK_NOTHROW(captain2.income());
            }else{
                CHECK(game.turn() == "Shlomi");
                CHECK_NOTHROW(captain2.block(captain));
                CHECK(captain.coins() == 3);
            }
        }
    }
}

TEST_CASE("Contessa special"){
    Game game{};
    Assassin assassin(game, "Yossi");
    Contessa contessa(game, "Gilad");
    Duke duke(game, "Moshe");
    bool duke_coup = false;
   

    for (int i = 0; i < 12; i++)
    {
        if (i % 3 == 0)
        {
            if (assassin.coins() < 3){
            CHECK(game.turn() == "Yossi");
            CHECK_NOTHROW(assassin.income());
            }else if (assassin.coins() == 3){
                CHECK_NOTHROW(assassin.coup(duke));
                CHECK(assassin.coins() == 0);
                duke_coup = true;
            }
            
        }
        else if (i % 3 == 1)
        {
            if (!duke_coup){
            CHECK(game.turn() == "Gilad");
            CHECK_NOTHROW(contessa.income());
            }else{
                CHECK_NOTHROW(contessa.block(assassin));
            }
        }else if (i % 3 == 2)
        {
            CHECK(game.turn() == "Moshe");
            CHECK_NOTHROW(duke.income());
            break;
        }
    }
}

TEST_CASE("Max players"){
    Game game{};
    CHECK_NOTHROW(Duke duke(game, "Moshe"));
    CHECK_NOTHROW(Assassin assassin(game, "Yossi"));
    CHECK_NOTHROW(Ambassador ambassador(game, "Meirav"));
    CHECK_NOTHROW(Captain captain(game, "Reut"));
    CHECK_NOTHROW(Contessa contessa(game, "Gilad"));
    CHECK_NOTHROW(Duke duke2(game, "Shlomi"));
    CHECK_THROWS(Assassin assassin2(game, "Or"));
}
   

