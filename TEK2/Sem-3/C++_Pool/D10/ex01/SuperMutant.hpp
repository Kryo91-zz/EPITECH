/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** SuperMutant.hpp
*/

#ifndef SUPERMUTANT_H_
#define SUPERMUTANT_H_

#include "AEnemy.hpp"

class SuperMutant : virtual public AEnemy
{
    public:
        SuperMutant();
        ~SuperMutant();
        virtual void takeDamage(int damage);
};

#endif