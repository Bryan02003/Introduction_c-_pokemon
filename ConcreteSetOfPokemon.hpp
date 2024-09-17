#ifndef CONCRETESETOFPOKEMON_HPP
#define CONCRETESETOFPOKEMON_HPP

#include "SetOfPokemon.hpp"

class ConcreteSetOfPokemon : public SetOfPokemon 
{
    public:
        Pokemon* getOnePokemonByName(std::string name) override;
        Pokemon* getOnePokemonById(int id) override;
};

#endif
