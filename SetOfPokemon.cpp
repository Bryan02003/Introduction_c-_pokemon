#include "SetOfPokemon.hpp"

#include <iostream>

void SetOfPokemon::displayList() 
{
    std::cout << "*********************************"<< std::endl;
    for(Pokemon * pokemon : arrayOfPokemon){
        pokemon->displayInfo();
    }
}

SetOfPokemon::SetOfPokemon(){
}