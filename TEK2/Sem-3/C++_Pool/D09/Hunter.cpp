/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Hunter.cpp
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, const int level, const std::string weaponName):
        Character(name, level), name(name), level(level), weapon(weaponName)
{
    this->Strength = 9;
    this->Stamina = 9;
    this->Intelligence = 5;
    this->Spirit = 6;
    this->Agility = 25;

    COUT << this->name << " is born from a tree" << ENDL;
}

Hunter::Hunter(const std::string &name, const int level):
        Character(name, level), name(name), level(level)
{
    this->Strength = 9;
    this->Stamina = 9;
    this->Intelligence = 5;
    this->Spirit = 6;
    this->Agility = 25;

    COUT << this->name << " is born from a tree" << ENDL;
}

Hunter::~Hunter(void) { }

int Hunter::RangeAttack(void)
{
    if (this->power < 25) {
        COUT << this->name << " out of power" << ENDL;
        return (0);
    }
    this->power -= 25;
    COUT << this->name << " uses his bow" << ENDL;
    return (20 + this->Agility);
}

int Hunter::CloseAttack(void)
{
    if (Hunter::Range)
        return (0);
    if (this->power < 30) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 30;
    std::cout << this->_name << " strikes with his " << this->weapon << std::endl;
    return (this->Strength + 20);
}

void Hunter::Heal(void)
{
    if (this->health == 100)
        return;
    this->health += 50;
    if (this->health > 100)
        this->health = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Hunter::RestorePower()
{
    this->power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}