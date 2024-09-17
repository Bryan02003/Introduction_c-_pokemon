#include "SetOfPokemon.hpp"
#include <iostream>
#include <string>

#ifndef POKEMONIS_HPP
#define POKEMONIS_HPP

class Pokedex:public SetOfPokemon
{
    private:
    static Pokedex* instance;
    

    public:
    static Pokedex* getInstance(std::string fileName);
    Pokedex(std::string fileName);
    Pokemon* getOnePokemonByName(string name);
    Pokemon* getOnePokemonById(int id);

    

    ~Pokedex();
};

#endif



