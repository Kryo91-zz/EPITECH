/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** SuperMutant.cpp
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant():
    AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    damage -= 3;
    if (damage < 0)
        return;
    this->_hp -= damage;
    if (this->_hp < 0)
        this->_hp = 0;
}