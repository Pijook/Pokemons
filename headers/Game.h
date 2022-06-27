//
// Created by Jakub on 6/24/2022.
//

#ifndef POKEMONS_GAME_H
#define POKEMONS_GAME_H

#include "Pokemon.h"
#include "Player.h"
#include "PokemonUtils.h"
#include <fstream>
#include <vector>

extern int difficulty;
extern std::vector<Player*> enemies;
extern Player* playerCharacter;

/**
 * Loads data from file if file exists
 * @return True if data got loaded
 */
bool loadData();

/**
 * Saves game data to files player.txt and enemies.txt
 */
void saveData();

/**
 * Requests player to choose difficulty
 */
void openChooseDifficulty();

/**
 * Requests player to choose pokemons that he wants to use
 */
void openChoosePokemons();

/**
 * Generates enemies and their pokemons based on difficulty level
 */
void generateEnemies();

/**
 * Clears all needed variables and starts game
 * Gets difficulty, player pokemon and generates enemies
 * Then starts fights
 */
void start();

/**
 * Requests player to choose pokemon to evolve
 * @param player Owner of pokemons
 */
void openEvolvePokemon(Player* player);

/**
 * Requests player to choose attack that he wants to use
 * @param player Player that owns pokemon
 * @return Attack that player chose
 */
Attack* openAttack(Player* player);

/**
 * Requests player to choose new pokemon
 * @param player Owner of pokemons
 */
void openChangePokemon(Player* player);

/**
 * Chooses random attack that SI enemy pokemon will use
 * @param player Owner of pokemons
 * @return Random attack of currently chosen pokemon
 */
Attack* enemyChooseAttack(Player* player);

/**
 * Chooses random pokemon that SI enemy will use from now on
 * @param player Owner of pokemons
 */
void enemyChangePokemon(Player* player);

/**
 * Starts battle beetwen two players
 * Returns true if player wins battle
 * @param player Player
 * @param enemy SI Enemy
 * @return Returns true if player won battle
 */
bool startBattle(Player* player, Player* enemy);


#endif //POKEMONS_GAME_H
