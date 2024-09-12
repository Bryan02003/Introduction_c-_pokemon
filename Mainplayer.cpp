#include <iostream>
#include "Player.hpp"
#include "Pokeball.hpp"
#include <vector>
#include <string>

int main()
{
    Pokeball* ball = new Pokeball();

    Player* player=new Player("Bryan",ball);

    player->displayPlayer();

    delete player;
    delete ball;

    return 0;
}

