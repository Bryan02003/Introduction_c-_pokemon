#include "Player.hpp"
#include <iostream>

Player:: Player(const std::string&name, Pokeball* pokeball):name(name),pokeball(pokeball){}

void Player::displayPlayer()
{
    std::cout<<"The Player: "<<name<<", has Pokeball: "<<(pokeball->hasPokemon() ? "Yes" : "No")<<std::endl;//Affiche si la pokeball est vide ou pas
}

Player::~Player(){};