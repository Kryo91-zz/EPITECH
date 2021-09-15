/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->_name = name;
    this->level = level;
    std::cout << this->_name << " Created" << std::endl;
}

Character::~Character(void) { }

const std::string &Character::getName(void) const
{
    return this->_name;
}

int Character::getLvl(void) const
{
    return this->level;
}

int Character::getPower(void) const
{
    return this->power;
}

int Character::getPv(void) const
{
    return this->health;
}

int Character::RangeAttack(void)
{
    if (this->power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 10;
    std::cout << this->_name << " tosses a stone" << std::endl;
    return (this->Strength + 5);
}

void Character::Heal(void)
{
    if (this->health == 100)
        return;
    this->health += 50;
    if (this->health > 100)
        this->health = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->health -= damage;
    if (this->health <= 0)
        std::cout << this->_name << " out of combat" << std::endl;
    else
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
}

int Character::CloseAttack(void)
{
    if (Character::Range)
        return (0);
    if (this->power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 10;
    std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    return (this->Strength + 10);
}