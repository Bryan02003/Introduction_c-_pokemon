Fonctionnalités

Exploration : Le joueur peut explorer des zones et rencontrer aléatoirement des Pokémon sauvages.
Combat : Lorsqu'un Pokémon sauvage apparaît, un combat s'engage. Le joueur peut gagner ou perdre en fonction de la situation.
Gestion des Pokémon : Le joueur possède une équipe de 6 Pokémon et peut les utiliser pour le combat.
Pokédex : Le jeu dispose d'un Pokédex contenant jusqu'à 721 Pokémon, répartis sur plusieurs générations.
Aléatoire : Les Pokémon sauvages rencontrés sont choisis de manière aléatoire, ce qui ajoute une touche d'imprévisibilité à chaque partie.

Gameplay
Le jeu passe par plusieurs états :

WAITING : Le jeu attend l'interaction de l'utilisateur pour commencer.
START_GAME : Le jeu se lance.
INIT_PLAYER : Le joueur est initialisé avec un nom et une équipe de Pokémon.
EXPLORATION : Le joueur explore des zones où il peut rencontrer des Pokémon.
COMBAT : Si un Pokémon sauvage est rencontré, un combat commence.
WIN : Le joueur gagne le combat.
GAME_OVER : Le joueur perd le combat ou termine le jeu.
Exploration et Rencontres : Lors de l'exploration, un générateur aléatoire décide si le joueur rencontre un Pokémon. Si un Pokémon est rencontré, il est choisi aléatoirement dans la liste des Pokémon disponibles.
Combat : Le joueur et le Pokémon sauvage échangent des attaques. Si le joueur gagne, l'état passe à WIN, sinon à GAME_OVER.
