#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>
#include <iterator>
#include "Pokedex.hpp"

Pokedex::Pokedex(string fileName):SetOfPokemon()
{
const std::string delimiter = ",";
    std::fstream fin;
    try
    {
        std::string line;
        fin.open(fileName);
        getline(fin, line);
        while (getline(fin, line))
        {

            std::regex regex(delimiter);
            std::sregex_token_iterator it(line.begin(), line.end(), regex, -1);
            std::vector<std::string> tokens(it, {});
            int id=std::stoi(tokens.at(0));
            std::string name=tokens.at(1);
            std::string game=tokens.at(2);
            double hitPoint=std::stod(tokens.at(5));
            double attack=std::stod(tokens.at(6));
            double defence=std::stod(tokens.at(7));
            int generation=std::stoi(tokens.at(10));
// const string &name, int id, double hitPoint, double attack, double defense, int generation)
            Pokemon *p = new Pokemon(name, id, hitPoint, attack, defence, generation);
            
            this->arrayOfPokemon(*p);
            // std::cout<<"----------- add new pokemone ------------"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

// Pokedex::Pokedex(string fileName):SetOfPokemon()
// {
//     std::ifstream file(fileName);
//     if(!file.is_open())
//     {
//         std::cerr<<"File"<<fileName<<"not found"<<std::endl;
//         return;
//     }
//     std::string line;
//     std::getline(file,line);
//     while(std::getline(file,line))
//     {
//         std::cout<<line<<std::endl;
//         std::stringstream inputstringstream(line);
//         std::string cell;
//         std::vector<std::string>lineData;

//         while(std::getline(inputstringstream,cell,','))
//         {
//             lineData.push_back(cell);
//             std::cout<<"-----------c"<<cell<<std::endl;
//         }
//         int id=std::stoi(lineData.at(0));
//         double attackValue = std::stod(lineData.at(6));
//         double hitPoint = std::stod(lineData.at(5));
//         double defenseValue = std::stod(lineData.at(7));
//         int generation = std::stoi(lineData.at(11));

//         arrayOfPokemon.push_back(new Pokemon(lineData.at(1), id, hitPoint, attackValue, defenseValue, generation));
//     }
// }
//     Pokemon* Pokedex::getOnePokemonByName(string name){return nullptr;}
//     Pokemon* Pokedex::getOnePokemonById(int id){return nullptr;}

//     Pokedex::~Pokedex(){}
