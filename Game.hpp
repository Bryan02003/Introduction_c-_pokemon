#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "Player.hpp"
#include "PokemonParty.hpp"
#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include "ConcreteSetOfPokemon.hpp"

enum GameState
{
    WAITING,
    START_GAME,
    INIT_PLAYER,
    EXPLORATION,
    COMBAT,
    WIN,
    GAME_OVER
};

class Game
{
    public:
        Game();
        void run(); //Démarrer la machine à états
        ~Game();
        Pokedex* pokedex;
    
    private:
        GameState currentState;
        Player* player;
        PokemonParty* party;
        ConcreteSetOfPokemon* wildPokemon;
        Pokemon* encounteredPokemon;

        void handleState();
        void initPlayer();
        void exploration();
        void combat();
        void win();
        void gameOver();

      
};

#endif

