#include <iostream>
#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include <vector>

using std::vector;

void main2() 
{
    std::cout << "******* Pokemon test *******" << std::endl;
    Pokemon pikachu("Pikachu",5,100,30,70,3);
    Pokemon Bryan("Bryan",10,100,100,50,3);

    Pokedex pokedex("./Ressources/pokedex.csv ");
    pikachu.displayInfo();
    Bryan.displayInfo();

    pikachu.attack(Bryan);
    Bryan.attack(pikachu);
    Bryan.attack(pikachu);
    Bryan.attack(pikachu);
    Bryan.attack(pikachu);

    std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;

}

int main()
{
    std::string file="./Ressources/pokedex.csv";
    Pokedex *p=new Pokedex(file);
}





