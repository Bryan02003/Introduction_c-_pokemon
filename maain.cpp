#include <iostream>
#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "Pokeball.hpp"
#include "PokemonParty.hpp"
#include <vector>
#include <string>

using std::vector;

// void main2() 
// {
//     std::cout << "******* Pokemon test *******" << std::endl;
//     Pokemon pikachu("Pikachu",5,100,45,50,2);
//     Pokemon Bryan("Bryan",10,100,70,30,3);

//     Pokedex pokedex("./Ressources/pokedex.csv ");
//     pikachu.displayInfo();
//     Bryan.displayInfo();

//     pikachu.attack(Bryan);
//     Bryan.attack(pikachu);
//     Bryan.attack(pikachu);
//     Bryan.attack(pikachu);
//     Bryan.attack(pikachu);

//     std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;

// }
// void main3()
// {
//     std::string file="./Ressources/pokedex.csv";
//     Pokedex *p=new Pokedex(file);
// }

// int main() {
//     std::string file = "./Ressources/pokedex.csv";
    
//     // Obtention de l'unique instance du Pokedex
//     Pokedex* pokedex = Pokedex::getInstance(file);

//     Pokemon* pikachu = pokedex->getOnePokemonByName("Pikachu");
//     if (pikachu != nullptr) {
//         pikachu->displayInfo();
//     } else {
//         std::cout << "Pikachu not found." << std::endl;
//     }

//     return 0;
// }

// int main() {
//     Pokemon* pikachu = new Pokemon("Pikachu", 5, 100, 45, 50, 2);

//     Pokeball pokeball;
//     pokeball.capture(pikachu);  // Capture du Pokémon

//     Pokemon* liberePokemon = pokeball.libere();  // Libération du Pokémon
//     if (liberePokemon != nullptr) {
//         liberePokemon->displayInfo();  // Affiche les informations du Pokémon libéré
//     }

//     delete liberePokemon;  
//     return 0;
// }

int main() 
{
    Pokedex* pokedex = Pokedex::getInstance("./Ressources/pokedex.csv");

    Pokemon* pikachu = pokedex->getOnePokemonByName("Pikachu");
    Pokemon* charmander = pokedex->getOnePokemonByName("Charmander");
    Pokemon* bulbasaur = pokedex->getOnePokemonByName("Bulbasaur");
    Pokemon* Voltorb = pokedex->getOnePokemonByName("Voltorb");
    Pokemon* Riolu = pokedex->getOnePokemonByName("Riolu");
    Pokemon* Lucario = pokedex->getOnePokemonByName("Lucario");

    Pokeball* ball = new Pokeball();
    ball->capture(pikachu);
    ball->capture(charmander); 
    ball->capture(bulbasaur);
    ball->capture(Voltorb);
    ball->capture(Riolu);
    ball->capture(Lucario);    

    PokemonParty* party = new PokemonParty("Pikachu", "Charmander", "Bulbasaur", "Voltorb", "Riolu", "Lucario", ball);

    std::cout << "Pokémon dans la partie: " << std::endl;
    for (const auto& pokemon : party->getPokemon()) 
    {
        pokemon->displayInfo();
    }

    party->addPokemonFromBall(ball);

    std::cout << "Pokémon après ajout depuis la Pokeball: " << std::endl;
    for (const auto& pokemon : party->getPokemon()) 
    {
        pokemon->displayInfo();
    }


    delete ball; 
    delete party;

    return 0;
}


