#include "SetOfPokemon.hpp"
#include <iostream>

#ifndef POKEMONIS_HPP
#define POKEMONIS_HPP

class Pokedex:public SetOfPokemon
{
    public:
    Pokedex(string name);
    Pokemon* getOnePokemonByName(string name);
    Pokemon* getOnePokemonById(int id);

    ~Pokedex();
};

#endif



