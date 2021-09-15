/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, const int level, const std::string weaponName):
        Character(name, level), Warrior(name, level, weaponName), Mage(name, level), Priest(name, level), name(name), level(level), Weapon(weaponName)
{
    this->Strength = 9;
    this->Stamina = 10;
    this->Intelligence = 10;
    this->Spirit = 10;
    this->Agility = 2;

    COUT << "the light falls on " << this->name << ENDL;
}

Paladin::Paladin(const std::string &name, const int level):
        Character(name, level), Warrior(name, level), Mage(name, level), Priest(name, level), name(name), level(level)
{
    this->Strength = 9;
    this->Stamina = 10;
    this->Intelligence = 10;
    this->Spirit = 10;
    this->Agility = 2;

    COUT << "the light falls on " << this->name << ENDL;
}

Paladin::~Paladin() { }

int Paladin::RangeAttack(void)
{
    return Priest::RangeAttack();
}

int Paladin::CloseAttack(void)
{
    return Warrior::CloseAttack();
}

void Paladin::Heal(void)
{
    return Priest::Heal();
}

void Paladin::RestorePower(void)
{
    return Warrior::RestorePower();
}

int Paladin::Intercept(void)
{
    if (this->RANGE == CLOSE)
        return (0);
    if (this->power < 10) {
        std::cout << this->name << " out of power" << std::endl;
        return (0); 
    }
    this->power -= 10;
    std::cout << this->name << " intercepts" << std::endl;
    Range = CLOSE;
    return (0);
}