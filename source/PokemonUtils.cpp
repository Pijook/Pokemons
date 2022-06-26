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

    Attack* waterGunAttack = new Attack("Water Gun", 40, 100);

    //1
    Pokemon* squirtle = new Pokemon(
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
    );
    squirtle->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " uses it's special attack Blob!" << std::endl;
        toAttack->decreaseHp(attacking->getSpecialAttack() * 2);
    });
    pokemons.push_back(squirtle);


    //2
    Pokemon* charmander = new Pokemon(
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
    );
    charmander->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " uses fire blast and sets " << toAttack->getName() << " on fire!" << std::endl;
        toAttack->decreaseHp(attacking->getSpecialAttack() * 1.5 + attacking->getSpecialAttack());
    });
    pokemons.push_back(charmander);

    //3
    Pokemon* pidgey = new Pokemon(
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
    );
    pidgey->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " increases it's speed!" << std::endl;
        attacking->setSpeed(attacking->getSpeed() + 5);
    });
    pokemons.push_back(pidgey);


    //4
    Pokemon* geodude = new Pokemon(
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
    );
    geodude->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " increases its defense!" << std::endl;
        attacking->setDefense(attacking->getDefense() + 10);
    });
    pokemons.push_back(geodude);

    //5
    Pokemon* ponyta = new Pokemon(
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
    );
    ponyta->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " increases its attack!" << std::endl;
        attacking->setAttack(attacking->getAttack() + 15);
    });
    pokemons.push_back(ponyta);

    //6
    Pokemon* magnemite = new Pokemon(
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
    );
    magnemite->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " uses its magnet and stoles iron from " << toAttack->getName() << std::endl;
        std::cout << toAttack->getName() << " attack decreases!" << std::endl;
        toAttack->setAttack(toAttack->getAttack() - 10);
    });
    pokemons.push_back(magnemite);

    //7
    Pokemon* tirtouga = new Pokemon(
            "Tirtouga",
            "water",
            {tackleAttack, biteAttack, new Attack("Aqua Jet", 40, 100), new Attack("Brine", 65, 100)},
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
    );
    tirtouga->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " spins and changes enemy stats!" << std::endl;
        toAttack->setAttack(toAttack->getAttack() + 500);
        toAttack->setHp(1);
    });
    pokemons.push_back(tirtouga);


    //8
    Pokemon* castform = new Pokemon(
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
    );
    castform->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " says blob" << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "..." << std::endl;
        std::cout << "Yes that's all" << std::endl;
    });
    pokemons.push_back(castform);

    //9
    Pokemon* mudkip = new Pokemon(
            "Mudkip",
            "water",
            {tackleAttack, biteAttack, waterGunAttack, new Attack("Water Pulse", 60, 100)},
            1,
            65,
            0,
            70,
            40,
            50,
            50,
            50,
            50,
            8
    );
    mudkip->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " throws mud at " << toAttack->getName() << std::endl;
        std::cout << toAttack->getName() << " attack decreases!" << std::endl;
        toAttack->setAttack(toAttack->getAttack() / 2);
    });
    pokemons.push_back(mudkip);

    //10
    Pokemon* amongus = new Pokemon(
            "Amoonguss",
            "earth",
            {new Attack("Vent", 20, 100), new Attack("Stab", 40, 100), new Attack("Hide body", 75, 100), new Attack("Do Task", 40, 100)},
            1,
            420,
            0,
            85,
            30,
            114,
            70,
            80,
            85,
            9
    );
    amongus->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << "AMOGUS" << std::endl;
        toAttack->setHp(toAttack->getHp() - 1);
    });
    pokemons.push_back(amongus);


    //11
    Pokemon* magikarp = new Pokemon(
            "Magikarp",
            "water",
            {new Attack("Splash", 0, 0), new Attack("Tsunami", 666, 100), new Attack("Mega Tsunami", 999999999, 100), new Attack("Blob", 1, 100)},
            1,
            20,
            0,
            50,
            100,
            300,
            1,
            500,
            700,
            10
    );
    magikarp->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << "Magikarp as strongest pokemon in game don't need to use any attacks" << std::endl;
        std::cout << "His existence just sets enemy pokemon health to 0" << std::endl;
        toAttack->setHp(0);
    });
    pokemons.push_back(magikarp);

    //12
    Pokemon* diglett = new Pokemon(
            "Diglett",
            "earth",
            {scratchAttack, biteAttack, new Attack("Mud slap", 20, 100), new Attack("Bulldoze", 60, 100)},
            1,
            50,
            0,
            55,
            95,
            10,
            25,
            45,
            35,
            11
    );
    diglett->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << "Dig dig dig!" << std::endl;
        attacking->setHp(attacking->getHp() + 50);
        attacking->setDefense(attacking->getDefense() +25);
    });
    pokemons.push_back(diglett);

    //13
    Pokemon* honedge = new Pokemon(
            "Honedge",
            "steel",
            {tackleAttack, slashAttack, biteAttack, slashAttack},
            1,
            79,
            0,
            80,
            28,
            45,
            100,
            37,
            35,
            12
    );
    honedge->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " unleashes its fury!" << std::endl;
        std::cout << attacking->getName() << " attacks is doubled!" << std::endl;
        attacking->setAttack(attacking->getAttack() * 2);
    });
    pokemons.push_back(honedge);

    //14
    Pokemon* meltan = new Pokemon(
            "Meltan",
            "steel",
            {tackleAttack},
            1,
            70,
            0,
            65,
            34,
            45,
            65,
            35,
            55,
            13
    );
    meltan->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << attacking->getName() << " unleashes its fury!" << std::endl;
        std::cout << attacking->getName() << " health is doubled!" << std::endl;
        attacking->setHp(attacking->getHp() * 2);
    });
    pokemons.push_back(meltan);

    //15
    Pokemon* palkia = new Pokemon(
            "Palkia",
            "water",
            {new Attack("Hydro Pump", 110, 80), new Attack("Aqua Tail", 90, 90), new Attack("Dragon Breath", 60, 100), new Attack("Thunder", 110, 70)},
            1,
            120,
            0,
            120,
            100,
            90,
            100,
            120,
            150,
            14
    );
    palkia->setSpecialMove([](Pokemon* attacking, Pokemon* toAttack) {
        std::cout << "Praise the sun \\o/" << std::endl;
        toAttack->setAttack(0);
        toAttack->setHp(0);
        toAttack->setDefense(0);
        toAttack->setSpeed(0);
    });
    pokemons.push_back(palkia);
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
