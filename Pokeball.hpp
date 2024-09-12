#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "Pokemon.hpp"

class Pokeball
{
    private:
    Pokemon* capturePokemon; // Pointe vers le Pokémon capturé

    public:
    Pokeball();

    void capture(Pokemon* pokemon); // Méthode pour capturer un Pokémon

    Pokemon* libere(); // permet de récupérer et supprimer le Pokémon capturé

    bool hasPokemon() const;

    ~Pokeball();
};

#endif