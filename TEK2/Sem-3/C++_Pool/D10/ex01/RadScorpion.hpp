/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** RadScorpion.hpp
*/

#ifndef RADSCORPION_H_
#define RADSCORPION_H_

#include "AEnemy.hpp"

class RadScorpion : virtual public AEnemy
{
    public:
        RadScorpion();
        ~RadScorpion();
};

#endif