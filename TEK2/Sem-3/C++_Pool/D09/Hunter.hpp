/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Hunter.hpp
*/

#ifndef HUNTER_HPP_
    #define HUNTER_HPP_

#include "Paladin.hpp"

class Hunter : virtual public Character
{
    protected :
        std::string name;
        int level;
        std::string weapon = "sword";
    public :
        Hunter(const std::string &name, const int level, const std::string weaponName);
        Hunter(const std::string &name, const int level);
        ~Hunter(void);

        int RangeAttack();
        int CloseAttack();

        void Heal();
        void RestorePower();
};

#endif // !HUNTER_HPP_