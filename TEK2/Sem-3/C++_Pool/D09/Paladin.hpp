/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Paladin.hpp
*/

#ifndef PALADIN_HPP_
    #define PALADIN_HPP_

#include "Priest.hpp"

class Paladin: virtual public Warrior, virtual public Priest
{
    protected :
        std::string name;
        int level;
        std::string Weapon = "hammer";
    public :
        Paladin(const std::string &name, const int level, const std::string weaponName);
        Paladin(const std::string &name, const int level);
        ~Paladin();

        int RangeAttack() override;
        int CloseAttack() override;

        void Heal() override;
        void RestorePower() override;

        int Intercept();
};

#endif // !PALADIN_HPP_