//
// Created by Jakub on 6/24/2022.
//

#include "../headers/PokemonUtils.h"

std::vector<Pokemon*> pokemons;

/**
 * Generates pokemons and adds then to pokemons vector
 */
void loadPokemons() {
    Attack* tackleAttack = new Attack("Tackle", 40, 100);
    Attack* biteAttack = new Attack("Bite", 60, 100);

    Attack* scratchAttack = new Attack("Scratch", 40, 100);
    Attack* slashAttack = new Attack("Slash", 70, 100);

    //1
    pokemons.push_back(new Pokemon(
            "Squirtle",
            "water",
            {tackleAttack, biteAttack, new Attack("Water Gun", 40, 100), new Attack("Aqua Tail", 90, 90)},
            1,
            66,
            0,
            48,
            43,
            44,
            65,
            64,
            50,
            0
    ));


    //2
    pokemons.push_back(new Pokemon(
            "Charmander",
            "fire",
            {scratchAttack, slashAttack, new Attack("Firespin", 35, 100), new Attack("Fire Fang", 65, 95)},
            1,
            66,
            0,
            52,
            65,
            39,
            43,
            50,
            60,
            1
            ));

    //3
    pokemons.push_back(new Pokemon(
            "Pidgey",
            "air",
            {scratchAttack, tackleAttack, new Attack("Gust", 40, 100), new Attack("Wing Attack", 60, 100)},
            1,
            70,
            0,
            45,
            56,
            40,
            40,
            35,
            35,
            2
    ));

    //4
    pokemons.push_back(new Pokemon(
            "Geodude",
            "earth",
            {tackleAttack, new Attack("Rollout", 30, 90), new Attack("Bulldoze", 60, 100), new Attack("Rock Blast", 25, 90)},
            1,
            68,
            0,
            80,
            20,
            40,
            100,
            30,
            30,
            3
            ));

    //5
    pokemons.push_back(new Pokemon(
            "Ponyta",
            "fire",
            {tackleAttack, biteAttack, new Attack("Ember", 40, 100), new Attack("FLame Charge", 50, 100)},
            1,
            70,
            0,
            70,
            70,
            70,
            70,
            70,
            70,
            4
            ));

    //6
    pokemons.push_back(new Pokemon(
            "Magnemite",
            "steel",
            {tackleAttack, new Attack("Thunder Shock", 40, 100), new Attack("Spark", 65, 100), new Attack("Discharge", 80, 100)},
            1,
            77,
            0,
            35,
            45,
            25,
            70,
            55,
            95,
            5
    ));

    //7
    pokemons.push_back(new Pokemon(
            "Tirtouga",
            "water",
            {tackleAttack, slashAttack, new Attack("Aqua Jet", 40, 100), new Attack("Brine", 65, 100)},
            1,
            77,
            0,
            35,
            45,
            25,
            70,
            55,
            95,
            6
    ));

    //8
    pokemons.push_back(new Pokemon(
            "Castform",
            "ice",
            {tackleAttack, new Attack("Powder Snow", 40, 100), new Attack("Blizzard", 110, 70), new Attack("Hydro pump", 110, 80)},
            1,
            70,
            0,
            70,
            70,
            70,
            70,
            70,
            70,
            7
    ));

}

Pokemon *loadPokemonFromFile(std::fstream* fstream) {
    std::string readText = "";
    std::getline(*fstream, readText);
    int pokemonIndex = std::stoi(readText);

    std::getline(*fstream, readText);
    int level = std::stoi(readText);

    std::getline(*fstream, readText);
    int expToLevelUp = std::stoi(readText);

    std::getline(*fstream, readText);
    int curentExp = std::stoi(readText);

    std::getline(*fstream, readText);
    int attack = std::stoi(readText);

    std::getline(*fstream, readText);
    int speed = std::stoi(readText);

    std::getline(*fstream, readText);
    int hp = std::stoi(readText);

    std::getline(*fstream, readText);
    int defense = std::stoi(readText);

    std::getline(*fstream, readText);
    int specialDefense = std::stoi(readText);

    std::getline(*fstream, readText);
    int specialAttack = std::stoi(readText);

    Pokemon* pokemon = new Pokemon(*pokemons.at(pokemonIndex));
    pokemon->setLevel(level);
    pokemon->setExpToLevelUp(expToLevelUp);
    pokemon->setCurrentExp(curentExp);
    pokemon->setAttack(attack);
    pokemon->setSpeed(speed);
    pokemon->setHp(hp);
    pokemon->setDefense(defense);
    pokemon->setSpecialDefense(specialDefense);
    pokemon->setSpecialAttack(specialAttack);
    return pokemon;
}

void savePokemonToFile(std::ofstream* ofstream, Pokemon *pokemon) {
    *ofstream << pokemon->getPokeIndex() << std::endl;
    *ofstream << pokemon->getLevel() << std::endl;
    *ofstream << pokemon->getExpToLevelUp() << std::endl;
    *ofstream << pokemon->getCurrentExp() << std::endl;
    *ofstream << pokemon->getAttack() << std::endl;
    *ofstream << pokemon->getSpeed() << std::endl;
    *ofstream << pokemon->getHp() << std::endl;
    *ofstream << pokemon->getDefense() << std::endl;
    *ofstream << pokemon->getSpecialDefense() << std::endl;
    *ofstream << pokemon->getSpecialAttack() << std::endl;
}
