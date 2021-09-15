/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** AWeapon.hpp
*/

#ifndef AWEAPON_H_
#define AWEAPON_H_

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

class AWeapon
{
    protected:
        std::string _name;
        int _damage;
        int _apcost;
    public:
        AWeapon(std::string const &name, int apcost, int damage);
        ~AWeapon();
        std::string const &getName() const {return(this->_name);};
        int getAPcost() const {return this->_apcost;};
        int getDamage() const {return this->_damage;};
        virtual void attack() const = 0;
};

#endif