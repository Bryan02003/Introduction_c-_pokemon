#include "PokemonParty.hpp"
#include "Pokedex.hpp"
#include <iostream>

PokemonParty::PokemonParty(const std::string& name1, const std::string& name2, const std::string& name3, const std::string& name4, const std::string& name5, const std::string& name6,Pokeball* pokeball)
{
    Pokedex* pokedex = Pokedex::getInstance("");
    std::vector<std::string> names = { name1, name2, name3, name4, name5, name6 };
    for (const std::string&name : names) 
    {
        if (!name.empty()) {
            Pokemon* pokemon = pokedex->getOnePokemonByName(name);
            if (pokemon != nullptr) 
            {
                arrayOfPokemon.push_back(pokemon);
            }
        }
    }
    
    addPokemonFromBall(pokeball); // Ajoute un Pokémon depuis la Pokeball s'il y en a un
}

PokemonParty::~PokemonParty(){}

void PokemonParty::addPokemonFromBall(Pokeball* pokeball)
{
    Pokemon* newPokemon = pokeball->libere(); 
    if (newPokemon != nullptr) {
        if (arrayOfPokemon.size() < 6) {
            arrayOfPokemon.push_back(newPokemon);
        } else {
            std::cout << "La partie est déjà complete !" << std::endl;
            delete newPokemon; 
        }
    }
}

Pokemon* PokemonParty::getOnePokemonByName(string name)
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

Pokemon* PokemonParty::getOnePokemonById(int id)
{
    return nullptr; 
}

std::vector<Pokemon*> PokemonParty::getPokemon() const 
{
    return arrayOfPokemon;
}
