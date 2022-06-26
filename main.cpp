#include <iostream>
#include "headers/PokemonUtils.h"
#include "headers/Game.h"

int main() {
    loadPokemons();
    start();
    saveData();
    return 0;
}

