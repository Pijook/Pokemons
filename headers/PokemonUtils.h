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

Pokemon* loadPokemonFromFile(std::fstream* fstream);
void savePokemonToFile(std::ofstream* ofstream, Pokemon* pokemon);

#endif //POKEMONS_POKEMONUTILS_H
