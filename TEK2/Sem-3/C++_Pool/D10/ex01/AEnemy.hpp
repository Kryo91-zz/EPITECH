/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** AEnemy.hpp
*/

#ifndef AENEMY_H_
#define AENEMY_H_

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

class AEnemy
{
    protected:
        std::string _type;
        int _hp;
    public:
        AEnemy(int hp, std::string const &type);
        virtual ~AEnemy();
        std::string getType() const {return this->_type;};
        int getHP() const {return this->_hp;};
        virtual void takeDamage(int damage);
};

#endif