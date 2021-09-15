/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** PlasmaRifle.cpp
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}