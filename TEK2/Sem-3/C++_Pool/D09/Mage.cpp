/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Mage.cpp
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level):
    Character(name, level), _name(name), level(level)
{
    this->Strength = 6;
    this->Stamina = 6;
    this->Intelligence = 12;
    this->Spirit = 11;
    this->Agility = 7;
    std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage() { }

int Mage::RangeAttack(void)
{
    if (this->power < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 25;
    std::cout << this->_name << " launches a fire ball" << std::endl;
    return (20 + this->Spirit);
}

int Mage::CloseAttack(void)
{
    if (Mage::Range)
        return (0);
    if (this->power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 10;
    this->Range = RANGE;
    std::cout << this->_name << " blinks" << std::endl;
    return (0);
}

void Mage::Heal(void)
{
    if (this->health == 100)
        return;
    this->health += 50;
    if (this->health > 100)
        this->health = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Mage::RestorePower()
{
    this->power += (50 + this->Intelligence);
    if (this->power >= 100)
        this->power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}
