//
// Created by Jakub on 6/25/2022.
//

#include "../headers/Help.h"

/**
 * Requests user to enter some valuue
 * If value is -h or --help then it shows help for given screen
 * @param screen Current screen
 * @return Value enter by player or -1 if user requested for help
 */
int requestForValue(std::string screen) {
    std::string value;
    std::cin >> value;

    if(value == "-h" || value == "--help"){
        std::cout << "Choose number that is next to option you want to select" << std::endl;
        if(screen == "battle"){
            std::cout << "1. Attack - choose to attack enemy pokemon" << std::endl;
            std::cout << "2. Change pokemon - choose to change to other pokemon" << std::endl;
            std::cout << "3. Evolve pokemon - choose to evolve pokemon to new stage" << std::endl;
        }
        else if(screen == "chooseDifficulty"){
            std::cout << "1. Easy - 4 enemies with 4 pokemons" << std::endl;
            std::cout << "2. Normal - 5 enemies with 4 pokemons" << std::endl;
            std::cout << "3. Hard - 5 enemies with 6 pokemons" << std::endl;
        }
        else if(screen == "chooseAttack"){
            std::cout << "Enter number that is next to attack you want to use on enemy pokemon" << std::endl;
        }
        else if(screen == "changePokemon"){
            std::cout << "Enter number that is next to pokemon that you want to choose" << std::endl;
        }
        else if(screen == "choosePokemon"){
            std::cout << "Enter number that is next to pokemon that you want to add to your team (you can have 6 pokemons in team)" << std::endl;
        }
        else if(screen == "evolvePokemonStage1"){
            std::cout << "Enter number that is next to pokemon that you want to evolve" << std::endl;
        }
        else if(screen == "evolvePokemonStage2"){
            std::cout << "Enter number that is next to stats that you want to upgrade (You can choose same stat twice)" << std::endl;
        }
        return -1;
    }
    else{
        for(char a : value) {
            if (std::isdigit(a) == 0) {
                return -1;
            }
        }
        return std::stoi(value);
    }
}
