/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = damage;
}

AWeapon::~AWeapon() {}

void AWeapon::attack() const {}