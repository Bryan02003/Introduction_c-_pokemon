#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>
#include <iterator>
#include "Pokedex.hpp"

Pokedex* Pokedex::instance=nullptr;

Pokedex::Pokedex(std::string fileName) : SetOfPokemon() 
{
    const std::string delimiter = ",";
    std::fstream fin;

    try 
    {
        std::string line;
        fin.open(fileName);
        getline(fin, line); // Ignore la première ligne (entêtes)

        while (getline(fin, line)) 
        {
            std::regex regex(delimiter);
            std::sregex_token_iterator it(line.begin(), line.end(), regex, -1);
            std::vector<std::string> tokens(it, {});
            
            int id = std::stoi(tokens.at(0));
            std::string name = tokens.at(1);
            std::string game = tokens.at(2);
            double hitPoint = std::stod(tokens.at(5));
            double attack = std::stod(tokens.at(6));
            double defence = std::stod(tokens.at(7));
            int generation = std::stoi(tokens.at(10));

            Pokemon* p = new Pokemon(name, id, hitPoint, attack, defence, generation);
            arrayOfPokemon.push_back(p);
        }
    }
    catch (std::exception& e) 
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

// Destructeur virtuel pour la classe Pokedex
Pokedex::~Pokedex() 
{
    // Permet de libérer la mémoire
    for (Pokemon* p : arrayOfPokemon) {
        delete p;
    }
    arrayOfPokemon.clear();
}

Pokemon* Pokedex::getOnePokemonByName(std::string name) 
{
    for (Pokemon* pokemon : arrayOfPokemon) 
    {
        if (pokemon->getName() == name) 
        {
            return pokemon;  // Retourne le Pokémon correspondant au nom
        }
    }
    return nullptr;  // Retourne nullptr si aucun Pokémon trouvé
}

Pokemon* Pokedex::getOnePokemonById(int id) 
{
    for (Pokemon* pokemon : arrayOfPokemon) 
    {
        if (pokemon->getId() == id) 
        {
            return pokemon;  // Retourne le Pokémon correspondant à l'ID
        }
    }
    return nullptr; 
}

Pokedex* Pokedex::getInstance(std::string fileName)
{
    if(instance==nullptr)
    {
        instance=new Pokedex(fileName);
    }
    return instance;
}


