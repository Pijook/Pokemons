//
// Created by Jakub on 6/24/2022.
//

#include "../headers/Attack.h"

const std::string &Attack::getName() const {
    return name;
}

void Attack::setName(const std::string &name) {
    Attack::name = name;
}

int Attack::getDamage() const {
    return damage;
}

void Attack::setDamage(int damage) {
    Attack::damage = damage;
}

int Attack::getAccuracy() const {
    return accuracy;
}

void Attack::setAccuracy(int accuracy) {
    Attack::accuracy = accuracy;
}

Attack::Attack(const std::string &name, int damage, int accuracy) : name(name), damage(damage), accuracy(accuracy) {}
