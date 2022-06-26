//
// Created by Jakub on 6/24/2022.
//

#ifndef POKEMONS_PLAYER_H
#define POKEMONS_PLAYER_H

#include <vector>
#include <string>
#include "Pokemon.h"

class Player {

private:
    std::string name;
    int selectedPokemon;
    std::vector<Pokemon*> playerPokemons;

public:
    Player(const std::string &name);

    /**
     * Checks if Player has any pokemons with HP greater than 0
     * @return Returns true if player has at least 1 pokemon with HP greater than 0
     */
    bool hasPokemonsAlive();

    int getSelectedPokemon() const;

    void setSelectedPokemon(int selectedPokemon);

    void addPokemon(Pokemon* pokemon);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Pokemon *> &getPlayerPokemons() const;

    void setPlayerPokemons(const std::vector<Pokemon *> &playerPokemons);

};


#endif //POKEMONS_PLAYER_H
