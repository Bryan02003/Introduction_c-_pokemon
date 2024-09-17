#include "ConcreteSetOfPokemon.hpp"
#include "Pokemon.hpp"

Pokemon* ConcreteSetOfPokemon::getOnePokemonByName(string name)
{
    for (auto* pokemon : arrayOfPokemon) 
    {
        if (pokemon->getName() == name) 
        {
            return pokemon;
        }
    }
    return nullptr;
}

Pokemon* ConcreteSetOfPokemon::getOnePokemonById(int id)
{
     for (auto* pokemon : arrayOfPokemon) 
    {
        if (pokemon->getId() == id) 
        {
            return pokemon;
        }
    }
    return nullptr;
}