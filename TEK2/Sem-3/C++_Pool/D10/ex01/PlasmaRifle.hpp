/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** PlasmaRifle.hpp
*/

#ifndef PLASMARIFLE_H_
#define PLASMARIFLE_H_

#include "AWeapon.hpp"

class PlasmaRifle : virtual public AWeapon
{
    public:
        PlasmaRifle();
        ~PlasmaRifle();
        virtual void attack() const;
};

#endif