/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(std::string const &name)
{
    this->_name = name;
    this->_ap = 40;
}

Character::~Character() {}

void Character::recoverAP()
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::attack(AEnemy *enemy)
{
    if (!this->_weapon)
        return;
    if (enemy && this->_ap >= this->_weapon->getAPcost()) {
        this->_ap -= this->_weapon->getAPcost();
        enemy->takeDamage(this->_weapon->getDamage());
        std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->attack();
        if (enemy->getHP() <= 0)
            delete enemy;
    }
}

std::ostream &operator<<(std::ostream &stream, Character const &caract)
{
    if(caract.getWeapon()) {
        (stream << caract.getName() << " has " << caract.getAP() << " AP and wields a " << caract.getWeapon()->getName() << std::endl);
        return stream;
    }
    stream << caract.getName() << " has " << caract.getAP() << " AP and is unarmed" << std::endl ;
    return stream;
}