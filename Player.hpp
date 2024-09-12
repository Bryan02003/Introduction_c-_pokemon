#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Pokeball.hpp"

class Player 
{
    private:
    std::string name;
    Pokeball* pokeball;
    
    public:
    Player(const std::string&name, Pokeball* pokeball);

    
    void displayPlayer();

    ~Player();
};  

#endif