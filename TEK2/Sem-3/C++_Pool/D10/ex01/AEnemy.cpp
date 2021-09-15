/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** AEnemy.cpp
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, std::string const &type)
{
    this->_type = type;
    this->_hp = hp;
}

AEnemy::~AEnemy() {}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_hp -= damage;
}