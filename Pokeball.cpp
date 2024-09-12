#include "Pokeball.hpp"
#include <iostream>

Pokeball::Pokeball():capturePokemon(nullptr) {}

// Capture d'un Pokémon
void Pokeball::capture(Pokemon* pokemon) 
{
    // if (capturePokemon != nullptr) {
    //     std::cout << "La pokeball contient déjà un pokemon " << std::endl;
    // } else {
    //     capturePokemon = pokemon;
    //     std::cout << "Pokemon capturé ! " << std::endl;
    // }
}

// Libération du Pokémon capturé
Pokemon* Pokeball::libere() 
{
    if (capturePokemon == nullptr) {
        std::cout << "Aucun pokémon a libéré ! " << std::endl;
        return nullptr;
    } else {
        Pokemon* liberePokemon = capturePokemon;
        capturePokemon = nullptr;  // Supprime le Pokémon de la Pokeball
        std::cout << "Pokemon libéré ! " << std::endl;
        return liberePokemon;
    }
}

bool Pokeball::hasPokemon() const
{
    return pokemon != nullptr;
}

Pokeball::~Pokeball() 
{
    if (capturePokemon != nullptr) {
        delete capturePokemon;  // Libère la mémoire si un Pokémon est toujours capturé
    }
}