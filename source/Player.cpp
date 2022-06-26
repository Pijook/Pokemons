//
// Created by Jakub on 6/24/2022.
//

#include "../headers/Player.h"

Player::Player(const std::string &name) : name(name) {
    selectedPokemon = 0;
}

/**
 * Checks if Player has any pokemons with HP greater than 0
 * @return Returns true if player has at least 1 pokemon with HP greater than 0
 */
bool Player::hasPokemonsAlive() {
    for(Pokemon* pokemon : playerPokemons){
        if(pokemon->getHp() > 0){
            return true;
        }
    }
    return false;
}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

const std::vector<Pokemon *> &Player::getPlayerPokemons() const {
    return playerPokemons;
}

void Player::setPlayerPokemons(const std::vector<Pokemon *> &playerPokemons) {
    Player::playerPokemons = playerPokemons;
}

int Player::getSelectedPokemon() const {
    return selectedPokemon;
}

void Player::setSelectedPokemon(int selectedPokemon) {
    Player::selectedPokemon = selectedPokemon;
}

void Player::addPokemon(Pokemon *pokemon) {
    playerPokemons.push_back(pokemon);
}


