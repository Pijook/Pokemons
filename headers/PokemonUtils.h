//
// Created by Jakub on 6/24/2022.
//

#ifndef POKEMONS_POKEMONUTILS_H
#define POKEMONS_POKEMONUTILS_H

#include "Pokemon.h"
#include <vector>
#include <fstream>

extern std::vector<Pokemon*> pokemons;

/**
 * Generates pokemons and adds then to pokemons vector
 */
void loadPokemons();

/**
 * Loads pokemon from given stream
 * @param fstream Stream that contains data of pokemon
 * @return Pointer to created pokemon
 */
Pokemon* loadPokemonFromFile(std::fstream* fstream);

/**
 * Saves pokemon to given stream
 * @param ofstream Stream to use to save
 * @param pokemon Pokemon to save
 */
void savePokemonToFile(std::ofstream* ofstream, Pokemon* pokemon);

#endif //POKEMONS_POKEMONUTILS_H
