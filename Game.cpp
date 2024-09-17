#include "Game.hpp"
std::string file="./Ressources/pokedex.csv";

Game::Game()
{
    currentState=WAITING;
    player=nullptr;
    party=nullptr;
    pokedex= new Pokedex(file);
    wildPokemon=new ConcreteSetOfPokemon;
    encounteredPokemon=nullptr;
}

void Game::run()
{
    while(currentState != GAME_OVER)
    {
        handleState();
    }
    std::cout<<"Fin du jeu. "<<std::endl;
}

void Game::handleState()
{
    switch(currentState)
    {
        case WAITING:
            std::cout<<"En attente..... Appuyez sur une touche "<<std::endl;
            std::cin.get(); 
            currentState = START_GAME;
            break;
        case START_GAME:
            std::cout << "Lancement du jeu... "<<std::endl;
            currentState = INIT_PLAYER;
            break;
        case INIT_PLAYER:
            initPlayer();
            currentState = EXPLORATION;
            break;
        case EXPLORATION:
            exploration();
            break;
        case COMBAT:
            combat();
            break;
        case WIN:
            win();
            break;
        case GAME_OVER:
            gameOver();
            break;
    }
};

void Game::initPlayer()
{
    std::cout<<"Initialisation du joueur... "<<std::endl;
    Pokeball* ball = new Pokeball;
    player= new Player("Bryan", ball);

    std::cout<<"Création de l'équipe de Pokemon... "<<std::endl;
    party= new PokemonParty("Pikachu", "Charmander", "Bulbasaur", "Voltorb", "Riolu", "Lucario", ball);
    player->displayPlayer();
};

void Game::exploration()
{
    std::cout<<"Vous explorez la zone... "<<std::endl;

    if(rand()%2==0)
    {
        std::cout<<"Un Pokémon sauvage vient d'apparaitre ! "<<std::endl;
        encounteredPokemon = wildPokemon->getOnePokemonById(rand()%721); // Afin de simuler un pokemon aléatoire
        std::cout<<"Vous avez rencontré un "<<encounteredPokemon->getName()<<"! "<<std::endl;
        currentState=COMBAT;
    }else{
        std::cout<<"Rien ne se passe, vous pouvez continuer l'exploration... "<<std::endl;
        currentState = EXPLORATION;

    }
}

void Game::combat()
{
    std::cout <<"Un combat commence avec"<<encounteredPokemon->getName()<<"! "<<std::endl;
    
    int result = rand() % 2;
    if (result == 1) {
        std::cout << "Vous avez gagné le combat contre " << encounteredPokemon->getName() << " !\n";
        currentState = WIN;
    } else {
        std::cout << "Vous avez perdu le combat...\n";
        currentState = GAME_OVER;
    }
}

void Game::win()
{
    std::cout<<"Félicitations, vous avez remporté le combat"<<std::endl;
    currentState=GAME_OVER;
}

void Game::gameOver() 
{
    std::cout<<"Game Over... "<<std::endl;
    
}

Game::~Game() {
    if (pokedex != nullptr) 
    {
        delete pokedex;
        pokedex = nullptr;
    }
    if (wildPokemon != nullptr) 
    {
        delete wildPokemon;
        wildPokemon = nullptr;
    }
    if (player != nullptr) 
    {
        delete player;
        player = nullptr;
    }
    if (party != nullptr) 
    {
        delete party;
        party = nullptr;
    }
    if (encounteredPokemon != nullptr) 
    {
        delete encounteredPokemon;
        encounteredPokemon = nullptr;
    }
}

