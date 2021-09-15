/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, const int lvl):
    Character(name, lvl), Mage(name, lvl), name(name), level(lvl)
{
    this->Strength = 4;
    this->Stamina = 4;
    this->Intelligence = 42;
    this->Spirit = 21;
    this->Agility = 2;
    COUT << this->name << " enters in the order" << ENDL;
}

Priest::~Priest() { }

int Priest::CloseAttack(void)
{
    if (this->Range == RANGE)
        return (0);
    if (this->power < 10) {
        COUT << this->name << " out of power" << ENDL;
        return (0); 
    }
    this->Range = RANGE;
    this->power -= 10;
    COUT << this->name << " uses a spirit explosion" << ENDL;
    return (10 + this->Spirit);
}

void Priest::Heal(void)
{
    if (this->power < 10)
        return;
    if (this->health == 100)
        return;
    this->power -= 10;
    this->health += 70;
    if (this->health > 100)
        this->health = 100;
    std::cout << this->_name << " casts a little heal spell" << std::endl;
}