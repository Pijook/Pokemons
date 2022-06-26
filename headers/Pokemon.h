//
// Created by Jakub on 6/24/2022.
//

#ifndef POKEMONS_POKEMON_H
#define POKEMONS_POKEMON_H

#include <string>
#include <iostream>
#include <vector>
#include "Attack.h"

class Pokemon {

private:
    std::string name;
    std::string type;
    std::vector<Attack*> attacks;
    int level;
    int expToLevelUp;
    int currentExp;
    int attack;
    int speed;
    int hp;
    int defense;
    int specialDefense;
    int specialAttack;
    int pokeIndex;

public:
    Pokemon(const std::string &name, const std::string &type, const std::vector<Attack *> &attacks, int level,
            int expToLevelUp, int currentExp, int attack, int speed, int hp, int defense, int specialDefense,
            int specialAttack, int pokeIndex);

    Pokemon(const Pokemon& oldPokemon);

    /**
     * Attacks enemy pokemon
     * @param toAttack
     * @param usedAttack
     */
    void attackPokemon(Pokemon* toAttack, Attack* usedAttack);

    /**
     * Returns random attack from this pokemon attacks
     * @return Random attack
     */
    Attack* returnRandomAttack();

    bool readyToEvolve();

    /**
     * Counts attack multiplier bases on pokemon and enemy elemental type
     * @param toAttack Pokemon to attack
     * @return Counted multiplier
     */
    double countAttackMultiplier(Pokemon* toAttack);

    void decreaseHp(int amount);

    void increaseExp(int amount);

    int getLevel() const;

    void setLevel(int level);

    const std::vector<Attack *> &getAttacks() const;

    void setAttacks(const std::vector<Attack *> &attacks);

    void showInfo();

    int getExpToLevelUp() const;

    void setExpToLevelUp(int expToLevelUp);

    int getCurrentExp() const;

    void setCurrentExp(int currentExp);

    const std::string &getName() const;

    int getPokeIndex() const;

    void setPokeIndex(int pokeIndex);

    void setName(const std::string &name);

    const std::string &getType() const;

    void setType(const std::string &type);

    int getAttack() const;

    void setAttack(int attack);

    int getSpeed() const;

    void setSpeed(int speed);

    int getHp() const;

    void setHp(int hp);

    int getDefense() const;

    void setDefense(int defense);

    int getSpecialDefense() const;

    void setSpecialDefense(int specialDefense);

    int getSpecialAttack() const;

    void setSpecialAttack(int specialAttack);


};


#endif //POKEMONS_POKEMON_H
