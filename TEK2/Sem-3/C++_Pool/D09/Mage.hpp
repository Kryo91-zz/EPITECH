/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Mage.hpp
*/

#ifndef MAGE_HPP_

     #define MAGE_HPP_


#include "Warrior.hpp"

class Mage : virtual public Character
{
    protected :
        std::string _name;
        int level;
    public :
        Mage(const std::string &name, int level);
        ~Mage();

        virtual int RangeAttack();
        int CloseAttack();

        void Heal();
        void RestorePower();
};

#endif // !MAGE_HPP_