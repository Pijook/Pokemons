//
// Created by Jakub on 6/25/2022.
//

#ifndef POKEMONS_HELP_H
#define POKEMONS_HELP_H

#include <string>
#include <iostream>

/**
 * Requests user to enter some valuue
 * If value is -h or --help then it shows help for given screen
 * @param screen Current screen
 * @return Value enter by player or -1 if user requested for help
 */
int requestForValue(std::string screen);

#endif //POKEMONS_HELP_H
