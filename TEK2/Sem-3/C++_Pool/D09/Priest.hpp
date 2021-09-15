/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** Priest.hpp
*/

#ifndef PRIEST_HPP_

    #define PRIEST_HPP_



#include "Mage.hpp"

class Priest : virtual public Mage
{
    protected :
        std::string name;
        int level;
    public :
        Priest(const std::string &name, int level);
        ~Priest(void);

        virtual void Heal(void);

        int CloseAttack(void);
};

#endif // !PRIEST_HPP_