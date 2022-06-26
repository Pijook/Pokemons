//
// Created by Jakub on 6/24/2022.
//

#include "../headers/Game.h"
#include "../headers/Help.h"

int difficulty;
int battleIndex;
std::vector<Player*> enemies;
Player* playerCharacter;

/**
 * Cleans all needed variables and starts game
 * Gets difficulty, player pokemon and generates enemies
 * Then starts fights
 */
void start(){
    for(Player* enemy : enemies){
        delete enemy;
    }
    delete playerCharacter;

    bool dataLoaded = loadData();

    if(!dataLoaded){
        std::cout << "Enter your nickname" << std::endl;
        std::string nickname;
        std::cin >> nickname;

        playerCharacter = new Player(nickname);

        openChooseDifficulty();
        openChoosePokemons();
        generateEnemies();

        battleIndex = 0;
    }
    else{
        loadData();
        std::cout << "Loaded saved data!" << std::endl;

        std::cout << playerCharacter->getName() << std::endl;
        for(Player* enemy : enemies){
            std::cout << enemy->getName() << std::endl;
        }
    }

    for(size_t i = battleIndex; i < enemies.size(); i++){
        Player* enemy = enemies.at(i);
        battleIndex = i;

        bool result = startBattle(playerCharacter, enemy);

        if(result){
            std::cout << "You won!" << std::endl;

            invalidDecision:
            std::cout << "Do you wish to continue?" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;

            int decision = requestForValue("nextFight");

            if(decision != 1 && decision != 2){
                goto invalidDecision;
            }
            else if(decision == 2){
                break;
            }
        }
        else{
            std::cout << "You lost!" << std::endl;
            std::cout << "Game over!" << std::endl;
            break;
        }
    }
}

bool loadData() {
    std::fstream* playerStream = new std::fstream("player.txt");

    if(!playerStream->good()){
        return false;
    }

    std::string readText;

    std::getline(*playerStream, readText);
    playerCharacter = new Player(readText);

    std::getline(*playerStream, readText);
    difficulty = std::stoi(readText);

    std::getline(*playerStream, readText);
    battleIndex = std::stoi(readText);

    while(std::getline(*playerStream, readText)){
        if(readText == ";"){
            Pokemon* pokemon = loadPokemonFromFile(playerStream);

            playerCharacter->addPokemon(pokemon);
        }
    }

    std::fstream* enemiesStream = new std::fstream("enemies.txt");

    while(std::getline(*enemiesStream, readText)){
        if(readText == "-"){
            std::getline(*enemiesStream, readText);
            std::string enemyName = readText;
            Player* enemy = new Player(enemyName);
            enemies.push_back(enemy);
        }
        else if(readText == ";"){
            Pokemon* pokemon = loadPokemonFromFile(enemiesStream);
            enemies.at(enemies.size() - 1)->addPokemon(pokemon);
        }
    }

    return true;
}

void saveData() {
    remove("player.txt");

    std::ofstream* playerStream = new std::ofstream("player.txt");

    *playerStream << playerCharacter->getName() << std::endl;
    *playerStream << difficulty << std::endl;
    *playerStream << battleIndex << std::endl;

    for(Pokemon* pokemon : playerCharacter->getPlayerPokemons()){
        *playerStream << ";" << std::endl;
        savePokemonToFile(playerStream, pokemon);
    }

    playerStream->close();

    remove("enemies.txt");

    std::ofstream* enemiesStream = new std::ofstream("enemies.txt");

    for(Player* player : enemies){
        *enemiesStream << "-" << std::endl;
        *enemiesStream << player->getName() << std::endl;

        for(Pokemon* pokemon : player->getPlayerPokemons()){
            *enemiesStream << ";" << std::endl;
            savePokemonToFile(enemiesStream, pokemon);
        }
    }

    enemiesStream->close();
}

/**
 * Requests player to choose difficulty
 */
void openChooseDifficulty(){
    invalidValue:
    std::cout << "Choose difficulty" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Normal" << std::endl;
    std::cout << "3. Hard" << std::endl;

    int value;
    value = requestForValue("chooseDifficulty");

    if(value < 1 || value > 3){
        std::cout << "Invalid value!";
        goto invalidValue;
    }

    difficulty = value;
}

/**
 * Requests player to choose pokemons that he wants to use
 */
void openChoosePokemons(){
    std::vector<size_t> usedPokemons;
    std::cout << "Choose your pokemons!" << std::endl;
    for(size_t i = 0; i < 6; i++){
        invalidDecision:
        for(size_t x = 0; x < pokemons.size(); x++){
            if(std::find(usedPokemons.begin(), usedPokemons.end(), x) != usedPokemons.end()){
                continue;
            }

            size_t optionNumber = x + 1;
            std::cout << optionNumber << ". " << pokemons.at(x)->getName() << std::endl;
        }

        int decision = requestForValue("choosePokemon");

        decision = decision - 1;

        if(decision < 0 || decision >= pokemons.size() || std::find(usedPokemons.begin(), usedPokemons.end(), decision) != usedPokemons.end()){
            std::cout << "Invalid option!" << std::endl;
            goto invalidDecision;
        }

        Pokemon* newPokemon = new Pokemon(*pokemons.at(decision));
        playerCharacter->addPokemon(newPokemon);
        std::cout << newPokemon->getName() << " joins your squad!" << std::endl;
        usedPokemons.push_back(decision);
    }

}

/**
 * Generates enemies and their pokemons based on difficulty level
 */
void generateEnemies(){
    int enemiesAmount;
    int pokemonsAmount;

    if(difficulty == 1){
        enemiesAmount = 4;
        pokemonsAmount = 4;
    }
    else if(difficulty == 2){
        enemiesAmount = 5;
        pokemonsAmount = 4;
    }
    else if(difficulty == 3){
        enemiesAmount = 5;
        pokemonsAmount = 6;
    }

    std::string names[] = {
            "Red",
            "Leaf",
            "Ethan",
            "Kris",
            "Lucas",
            "Dawn",
            "Hilbert",
            "Hilda",
            "Nate",
            "Rosa",
            "Calem",
            "Serena",
            "Elaine",
            "Victor"};

    std::vector<int> usedNames;

    for(size_t i = 0; i < enemiesAmount; i++){
        int nameIndex = rand() % names->length();
        while(std::find(names->begin(), names->end(), nameIndex) != names->end()){
            nameIndex = rand() % names->length();
        }

        std::string name = names[nameIndex];
        Player* enemy = new Player(name);

        std::vector<size_t> usedPokemons;

        for(size_t x = 0; x < pokemonsAmount; x++){
            size_t index = rand() % pokemons.size();

            while(std::find(usedPokemons.begin(), usedPokemons.end(), index) != usedPokemons.end()){
                index = rand() % pokemons.size();
            }

            Pokemon* newPokemon = new Pokemon(*pokemons.at(index));
            enemy->addPokemon(newPokemon);
            usedPokemons.push_back(index);
        }

        enemies.push_back(enemy);
    }
}

/**
 * Starts battle beetwen two players
 * Returns true if player wins battle
 * @param player Player
 * @param enemy SI Enemy
 * @return Returns true if player won battle
 */
bool startBattle(Player* player, Player* enemy){
    std::cout << player->getName() << " VS " << enemy->getName() << std::endl;
    int decision = 0;
    int turn = 0;

    std::vector<int> pokemonsUsedInBattle;

    std::cout << player->getName() << " chooses " << player->getPlayerPokemons().at(player->getSelectedPokemon())->getName() << std::endl;
    std::cout << enemy->getName() << " chooses " << enemy->getPlayerPokemons().at(enemy->getSelectedPokemon())->getName() << std::endl;
    std::cout << "Fight!" << std::endl;
    while(player->hasPokemonsAlive() && enemy->hasPokemonsAlive()){
        std::cout << "============" << std::endl;
        if(turn == 0){
            std::cout << player->getName() << " turn" << std::endl;
            invalidDecision:
            std::cout << "What do you want to do?" << std::endl;
            std::cout << "1. Attack" << std::endl;
            std::cout << "2. Change pokemon" << std::endl;
            std::cout << "3. Evolve pokemon" << std::endl;

            decision = requestForValue("battle");

            if(decision == 1){
                Attack* attack = openAttack(player);
                player->getPlayerPokemons().at(player->getSelectedPokemon())->attackPokemon(enemy->getPlayerPokemons().at(enemy->getSelectedPokemon()), attack);

                if(std::find(pokemonsUsedInBattle.begin(), pokemonsUsedInBattle.end(), player->getSelectedPokemon()) == pokemonsUsedInBattle.end()){
                    pokemonsUsedInBattle.push_back(player->getSelectedPokemon());
                }

                if(enemy->getPlayerPokemons().at(enemy->getSelectedPokemon())->getHp() <= 0){
                    enemyChangePokemon(enemy);
                }
            }
            else if(decision == 2){
                openChangePokemon(player);
            }
            else if(decision == 3){
                bool hasPokemonsToEvolve = false;
                for(Pokemon* pokemon : player->getPlayerPokemons()){
                    if(pokemon->readyToEvolve()){
                        hasPokemonsToEvolve = true;
                        break;
                    }
                }

                if(hasPokemonsToEvolve){
                    openEvolvePokemon(player);
                }
                else{
                    std::cout << "You don't have pokemons that can evolve!" << std::endl;
                    goto invalidDecision;
                }
            }
            else{
                std::cout << "Choose correct option!" << std::endl;
                goto invalidDecision;
            }

            turn = 1;
        }
        else{
            std::cout << enemy->getName() << " turn" << std::endl;
            Attack* attack = enemyChooseAttack(enemy);

            enemy->getPlayerPokemons().at(enemy->getSelectedPokemon())->attackPokemon(player->getPlayerPokemons().at(player->getSelectedPokemon()), attack);

            if(player->getPlayerPokemons().at(player->getSelectedPokemon())->getHp() <= 0){
                openChangePokemon(player);
            }

            turn = 0;
        }
    }

    if(player->hasPokemonsAlive()){
        for(int pokemonIndex : pokemonsUsedInBattle){
            int amount = rand() % 100 + 1;
            player->getPlayerPokemons().at(pokemonIndex)->increaseExp(amount);
        }
        return true;
    }
    else{
        return false;
    }
}

/**
 * Requests player to choose attack that he wants to use
 * @param player Player that owns pokemon
 * @return Attack that player chose
 */
Attack* openAttack(Player* player) {
    Pokemon* pokemon = player->getPlayerPokemons().at(player->getSelectedPokemon());

    invalidDecision:
    std::cout << "Choose attack!" << std::endl;
    std::cout << pokemon->getName() << " attacks" << std::endl;

    for(size_t i = 0; i < pokemon->getAttacks().size(); i++){
        size_t optionNumber = i + 1;
        std::cout << optionNumber << ". " << pokemon->getAttacks().at(i)->getName() << std::endl;
    }

    int decision = 0;

    decision = requestForValue("chooseAttack");
    decision = decision - 1;

    if(decision < 0 || decision >= pokemon->getAttacks().size()){
        std::cout << "Invalid value!";
        goto invalidDecision;
    }

    return pokemon->getAttacks().at(decision);
}

/**
 * Requests player to choose new pokemon
 * @param player Owner of pokemons
 */
void openChangePokemon(Player* player) {
    invalidDecision:
    std::cout << "Choose new pokemon!" << std::endl;
    int decision = 0;

    for(size_t i = 0; i < player->getPlayerPokemons().size(); i++){
        size_t optionNumber = i + 1;
        Pokemon* pokemon = player->getPlayerPokemons().at(i);

        if(pokemon->getHp() <= 0){
            continue;
        }

        std::cout << optionNumber << ". " << pokemon->getName() << std::endl;
    }

    decision = requestForValue("changePokemon");
    decision = decision - 1;

    if(decision < 0 || decision >= player->getPlayerPokemons().size()){
        std::cout << "Invalid value!";
        goto invalidDecision;
    }

    Pokemon* newPokemon = player->getPlayerPokemons().at(decision);

    if(newPokemon->getHp() <= 0){
        std::cout << "This pokemon is unconscious! You must choose other pokemon!" << std::endl;
        goto invalidDecision;
    }

    player->setSelectedPokemon(decision);
    std::cout << player->getName() << " chooses " << newPokemon->getName() << "!" << std::endl;
}

/**
 * Requests player to choose pokemon to evolve
 * @param player Owner of pokemons
 */
void openEvolvePokemon(Player* player) {
    invalidDecision:
    int index = 1;
    for(Pokemon* pokemon : player->getPlayerPokemons()){
        if(!pokemon->readyToEvolve()){
            continue;
        }

        std::cout << index << ". " << pokemon->getName() << std::endl;
    }

    int decision;
    decision = requestForValue("evolvePokemonStage1");

    if(decision < 0 || decision >= player->getPlayerPokemons().size()){
        goto invalidDecision;
    }

    if(!player->getPlayerPokemons().at(decision)->readyToEvolve()){
        std::cout << "This pokemon is not ready to evolve" << std::endl;
        goto invalidDecision;
    }

    int stat1;
    int stat2;

    invalidStat:

    std::cout << "Choose statistics to evolve (2)" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Health" << std::endl;
    std::cout << "3. Speed" << std::endl;
    std::cout << "4. Defense" << std::endl;

    stat1 = requestForValue("evolvePokemonStage2");

    if(stat1 < 1 || stat1 > 4){
        goto invalidStat;
    }
    stat2 = requestForValue("evolvePokemonStage2");
    if(stat2 < 1 || stat2 > 4){
        goto invalidStat;
    }

    Pokemon* selectedPokemon = player->getPlayerPokemons().at(player->getSelectedPokemon());

    if(stat1 == 1){
        selectedPokemon->setAttack(selectedPokemon->getAttack() + 5);
    }
    else if(stat1 == 2){
        selectedPokemon->setHp(selectedPokemon->getHp() + 20);
    }
    else if(stat1 == 3){
        selectedPokemon->setSpeed(selectedPokemon->getSpeed() + 2);
    }
    else if(stat1 == 4){
        selectedPokemon->setDefense(selectedPokemon->getDefense() + 10);
    }

    if(stat2 == 1){
        selectedPokemon->setAttack(selectedPokemon->getAttack() + 5);
    }
    else if(stat2 == 2){
        selectedPokemon->setHp(selectedPokemon->getHp() + 20);
    }
    else if(stat2 == 3){
        selectedPokemon->setSpeed(selectedPokemon->getSpeed() + 2);
    }
    else if(stat2 == 4){
        selectedPokemon->setDefense(selectedPokemon->getDefense() + 10);
    }

    selectedPokemon->setLevel(selectedPokemon->getLevel() + 1);
    selectedPokemon->setCurrentExp(0);
    selectedPokemon->setExpToLevelUp(selectedPokemon->getExpToLevelUp() * 1.5);

    std::cout << selectedPokemon->getName() << " reached " << selectedPokemon->getLevel() << " level!" << std::endl;
    std::cout << "New stats:" << std::endl;
    std::cout << "Attack: " << selectedPokemon->getAttack() << std::endl;
    std::cout << "Health: " << selectedPokemon->getHp() << std::endl;
    std::cout << "Speed: " << selectedPokemon->getSpeed() << std::endl;
    std::cout << "Defense: " << selectedPokemon->getDefense() << std::endl;
}

/**
 * Chooses random attack that SI enemy pokemon will use
 * @param player Owner of pokemons
 * @return Random attack of currently chosen pokemon
 */
Attack *enemyChooseAttack(Player *player) {
    Pokemon* pokemon = player->getPlayerPokemons().at(player->getSelectedPokemon());
    return pokemon->returnRandomAttack();
}

/**
 * Chooses random pokemon that SI enemy will use from now on
 * @param player Owner of pokemons
 */
void enemyChangePokemon(Player *player) {
    if(!player->hasPokemonsAlive()){
        return;
    }

    srand(time(NULL));

    Pokemon* newPokemon = nullptr;

    while (newPokemon == nullptr){
        int index = rand() % player->getPlayerPokemons().size();
        if(player->getPlayerPokemons().at(index)->getHp() > 0){
            newPokemon = player->getPlayerPokemons().at(index);
            player->setSelectedPokemon(index);
        }
    }

    std::cout << player->getName() << " chooses " << newPokemon->getName() << "!" << std::endl;
}

