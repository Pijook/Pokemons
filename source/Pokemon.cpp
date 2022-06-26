//
// Created by Jakub on 6/24/2022.
//

#include "../headers/Pokemon.h"

void Pokemon::showInfo() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Exp: " << getCurrentExp() << "/" << getExpToLevelUp() << std::endl;
    std::cout << "Attack: " << getAttack() << std::endl;
    std::cout << "HP: " << getHp() << std::endl;
    std::cout << "Speed: " << getSpeed() << std::endl;
    std::cout << "Defense: " << getDefense() << std::endl;
    std::cout << "Special Attack: " << getSpecialAttack() << std::endl;
    std::cout << "Special Defense: " << getSpecialDefense() << std::endl;

}

/**
* Returns random attack from this pokemon attacks
* @return Random attack
*/
Attack* Pokemon::returnRandomAttack(){
    srand(time(NULL));
    return getAttacks().at(rand() % getAttacks().size());
}

/**
* Attacks enemy pokemon
* @param toAttack
* @param usedAttack
*/
void Pokemon::attackPokemon(Pokemon *toAttack, Attack* usedAttack) {
    double attackMultiplier = countAttackMultiplier(toAttack);

    srand(time(NULL));

    double critical = 1.0;

    /*for(int i = 0; i < 10; i++){
        std::cout <<  ((double)(rand() % 100 + 85) / 100) << std::endl;
    }*/

    if(rand() % 100 + 1 <= 25){
        critical = 1.5;
    }

    int damage =  ((getAttack() + usedAttack->getDamage()) / 4) * attackMultiplier * ((double)(rand() % 100 + 85) / 100) * critical;
    damage = damage - (toAttack->getDefense() / 4);

    if(damage < 0){
        damage = 0;
    }

    int dodgeChance = toAttack->getSpeed() / 4;

    bool dodged = (rand() % 100 + 1) <= dodgeChance;

    bool missed = (rand() % 100 + 1) > usedAttack->getAccuracy();

    if(dodged){
        std::cout << getName() << " used attack " << usedAttack->getName() << " tried to deal " << damage << " to " << toAttack->getName() << std::endl;
        std::cout << toAttack->getName() << "dodged!" << std::endl;
    }
    else if(missed){
        std::cout << getName() << " used attack " << usedAttack->getName() << " but missed! " << std::endl;
    }
    else{
        toAttack->decreaseHp(damage);
        std::cout << getName() << " used attack " << usedAttack->getName() << " and dealt " << damage << " to " << toAttack->getName() << std::endl;
        if(critical == 1.5){
            std::cout << "It was critical hit!" << std::endl;
        }

        if(attackMultiplier == 2.0){
            std::cout << "It was very effective!" << std::endl;
        }
        else if(attackMultiplier == 0.5){
            std::cout << "It wasn't very effective!" << std::endl;
        }

        std::cout << toAttack->getName() << " HP decrease to " << toAttack->getHp() << std::endl;
    }

    if(toAttack->getHp() < 0){
        std::cout << toAttack->getName() << " fainted!" << std::endl;
    }

}

/**
 * Counts attack multiplier bases on pokemon and enemy elemental type
 * @param toAttack Pokemon to attack
 * @return Counted multiplier
 */
double Pokemon::countAttackMultiplier(Pokemon *toAttack) {
    double effectiveMultiplier = 2.0;
    double notEffectiveMultiplier = 0.5;
    double normalMultiplier = 1.0;

    if(getType() == "water"){
        if(toAttack->getType() == "earth" || toAttack->getType() == "fire"){
            return effectiveMultiplier;
        }
        else if(toAttack->getType() == "water"){
            return notEffectiveMultiplier;
        }
    }
    else if(getType() == "earth"){
        if(toAttack->getType() == "fire" || toAttack->getType() == "ice" || toAttack->getType() == "steel"){
            return effectiveMultiplier;
        }
        else if(toAttack->getType() == "air"){
            return notEffectiveMultiplier;
        }
    }
    else if(getType() == "air"){
        if(toAttack->getType() == "ice"){
            return effectiveMultiplier;
        }
        else if(toAttack->getType() == "earth" || toAttack->getType() == "steel"){
            return notEffectiveMultiplier;
        }
    }
    else if(getType() == "fire"){
        if(toAttack->getType() == "ice" || toAttack->getType() == "steel"){
            return effectiveMultiplier;
        }
        else if(toAttack->getType() == "water" || toAttack->getType() == "earth"){
            return notEffectiveMultiplier;
        }
    }
    else if(getType() == "ice"){
        if(toAttack->getType() == "earth"){
            return effectiveMultiplier;
        }
        else if(toAttack->getType() == "water" || toAttack->getType() == "fire" || toAttack->getType() == "ice"){
            return notEffectiveMultiplier;
        }
    }
    else if(getType() == "steel"){
        if(toAttack->getType() == "water" || toAttack->getType() == "air"){
            return effectiveMultiplier;
        }
        else if(toAttack->getType() == "fire" || toAttack->getType() == "steel"){
            return notEffectiveMultiplier;
        }
    }

    return normalMultiplier;
}

void Pokemon::decreaseHp(int amount) {
    hp = hp - amount;
}

void Pokemon::increaseExp(int amount) {
    currentExp = currentExp + amount;
    std::cout << name << " earned " << amount << " exp!" << std::endl;

    if(currentExp >= expToLevelUp){
        std::cout << name << " is ready to evolve!" << std::endl;
    }
}

const std::string &Pokemon::getName() const {
    return name;
}

void Pokemon::setName(const std::string &name) {
    Pokemon::name = name;
}

int Pokemon::getAttack() const {
    return attack;
}

void Pokemon::setAttack(int attack) {
    Pokemon::attack = attack;
}

int Pokemon::getSpeed() const {
    return speed;
}

void Pokemon::setSpeed(int speed) {
    Pokemon::speed = speed;
}

int Pokemon::getHp() const {
    return hp;
}

void Pokemon::setHp(int hp) {
    Pokemon::hp = hp;
}

int Pokemon::getDefense() const {
    return defense;
}

void Pokemon::setDefense(int defense) {
    Pokemon::defense = defense;
}

int Pokemon::getSpecialDefense() const {
    return specialDefense;
}

void Pokemon::setSpecialDefense(int specialDefense) {
    Pokemon::specialDefense = specialDefense;
}

int Pokemon::getSpecialAttack() const {
    return specialAttack;
}

void Pokemon::setSpecialAttack(int specialAttack) {
    Pokemon::specialAttack = specialAttack;
}

const std::string &Pokemon::getType() const {
    return type;
}

void Pokemon::setType(const std::string &type) {
    Pokemon::type = type;
}

int Pokemon::getExpToLevelUp() const {
    return expToLevelUp;
}

void Pokemon::setExpToLevelUp(int expToLevelUp) {
    Pokemon::expToLevelUp = expToLevelUp;
}

int Pokemon::getCurrentExp() const {
    return currentExp;
}

void Pokemon::setCurrentExp(int currentExp) {
    Pokemon::currentExp = currentExp;
}

const std::vector<Attack *> &Pokemon::getAttacks() const {
    return attacks;
}

void Pokemon::setAttacks(const std::vector<Attack *> &attacks) {
    Pokemon::attacks = attacks;
}

Pokemon::Pokemon(const Pokemon& oldPokemon) {
    this->name = oldPokemon.name;
    this->type = oldPokemon.type;
    this->attacks = oldPokemon.attacks;
    this->expToLevelUp = oldPokemon.expToLevelUp;
    this->currentExp = oldPokemon.currentExp;
    this->attack = oldPokemon.attack;
    this->speed = oldPokemon.speed;
    this->hp = oldPokemon.hp;
    this->defense = oldPokemon.defense;
    this->specialDefense = oldPokemon.specialDefense;
    this->specialAttack = oldPokemon.specialAttack;
    this->level = oldPokemon.level;
    this->pokeIndex = oldPokemon.pokeIndex;
}

bool Pokemon::readyToEvolve() {
    return getCurrentExp() >= expToLevelUp;
}

int Pokemon::getLevel() const {
    return level;
}

void Pokemon::setLevel(int level) {
    Pokemon::level = level;
}

int Pokemon::getPokeIndex() const {
    return pokeIndex;
}

void Pokemon::setPokeIndex(int pokeIndex) {
    Pokemon::pokeIndex = pokeIndex;
}

Pokemon::Pokemon(const std::string &name, const std::string &type, const std::vector<Attack *> &attacks, int level,
                 int expToLevelUp, int currentExp, int attack, int speed, int hp, int defense, int specialDefense,
                 int specialAttack, int pokeIndex) : name(name), type(type), attacks(attacks), level(level),
                                                     expToLevelUp(expToLevelUp), currentExp(currentExp), attack(attack),
                                                     speed(speed), hp(hp), defense(defense),
                                                     specialDefense(specialDefense), specialAttack(specialAttack),
                                                     pokeIndex(pokeIndex) {}

