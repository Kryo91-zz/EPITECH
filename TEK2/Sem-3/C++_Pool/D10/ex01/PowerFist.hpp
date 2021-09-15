/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** PowerFist.hpp
*/

#ifndef POWERFIST_H_
#define POWERFIST_H_

#include "AWeapon.hpp"

class PowerFist : virtual public AWeapon
{
    public:
        PowerFist();
        ~PowerFist();
        virtual void attack() const;
};

#endif