//
// Created by Jakub on 6/24/2022.
//

#ifndef POKEMONS_ATTACK_H
#define POKEMONS_ATTACK_H

#include <string>

class Attack {

private:
    std::string name;
    int damage;
    int accuracy;

public:
    Attack(const std::string &name, int damage, int accuracy);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getDamage() const;

    void setDamage(int damage);

    int getAccuracy() const;

    void setAccuracy(int accuracy);

};


#endif //POKEMONS_ATTACK_H
