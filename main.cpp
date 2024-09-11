#include "Pokemon.hpp"
#include <iostream>

int main()
{
    std::cout<<"Pokemon test"<<std::endl;
    Pokemon pikachu("pikachu",1,25,35,55,1);

    Pokemon copie(pikachu);
    Pokemon displayInfo(pikachu);

    return 0;
}