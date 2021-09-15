/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Warrior.hpp
*/

#ifndef WARRIOR_HPP_

    #define WARRIOR_HPP_

#include <ostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include "Character.hpp"

class Warrior : virtual public Character
{
    protected :
        std::string _name;
        int level;
        std::string weaponName = "hammer";
    public :
        Warrior(const std::string &name, int level);
        Warrior(const std::string &name, int level, const std::string weaponName);
        ~Warrior();

        int RangeAttack();
        virtual int CloseAttack();

        void Heal();
        virtual void RestorePower();
};

#endif // !WARRIOR_HPP_
