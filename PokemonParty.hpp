#ifndef POKEMONPARTY_HPP
#define POKEMONPARTY_HPP

#include "Pokeball.hpp"
#include "SetOfPokemon.hpp"
#include "Pokemon.hpp"

#include <string>
#include <vector>

class PokemonParty : public SetOfPokemon
{
    private:
    Pokeball* pokeball;

    public:
    PokemonParty(const std::string&name1, const std::string& name2, const std::string&name3, const std::string&name4, const std::string&name5, const std::string&name6, Pokeball* ball);

    void addPokemonFromBall(Pokeball* pokeball);
    Pokemon* getOnePokemonByName(string name) override;
    Pokemon* getOnePokemonById(int id) override;

    std:: vector <Pokemon* > getPokemon() const;

    ~PokemonParty();
};

#endif