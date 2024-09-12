#include "SetOfPokemon.hpp"
#include <iostream>
#include <string>

#ifndef POKEMONIS_HPP
#define POKEMONIS_HPP

class Pokedex:public SetOfPokemon
{
    private:
    static Pokedex* instance;
    Pokedex(std::string fileName);

    public:
    static Pokedex* getInstance(std::string fileName);
    // Pokedex(string name);
    Pokemon* getOnePokemonByName(string name);
    Pokemon* getOnePokemonById(int id);

    

    ~Pokedex();
};

#endif



