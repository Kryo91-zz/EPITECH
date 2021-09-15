/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Warrior.cpp
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level):
        Character(name, level), _name(name), level(level)
{
    this->Strength = 12;
    this->Stamina = 12;
    this->Intelligence = 6;
    this->Spirit = 5;
    this->Agility = 7;
    std::cout << "I'm "<< this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::Warrior(const std::string &name, int level, const std::string weaponName):
        Character(name, level), _name(name), level(level), weaponName(weaponName)
{
    std::cout << "I'm "<< this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior() { }

int Warrior::RangeAttack(void)
{
    if (this->RANGE == CLOSE)
        return (0);
    if (this->power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 10;
    std::cout << this->_name << " intercepts" << std::endl;
    this->Range = CLOSE;
    return (0);
}

int Warrior::CloseAttack(void)
{
    if (Warrior::Range)
        return (0);
    if (this->power < 30) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 30;
    std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
    return (this->Strength + 20);
}

void Warrior::Heal(void)
{
    if (this->health == 100)
        return;
    this->health += 50;
    if (this->health > 100)
        this->health = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Warrior::RestorePower()
{
    this->power = 100;
    std::cout << this->_name << " eats" << std::endl;
}
