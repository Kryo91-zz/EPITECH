/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** character.hpp
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_
    #define COUT std::cout
    #define ENDL std::endl

#include <ostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>

class Character
{
    protected :
        std::string _name;
        int level;
        int Strength = 5;
        int Stamina = 5;
        int Intelligence = 5;
        int Spirit = 5;
        int Agility = 5;
        int health = 100;
        int power = 100;
    public :
        Character(const std::string &name, int level);
        ~Character(void);
        const std::string &getName(void) const;
        int getLvl(void) const;
        int getPv() const;
        int getPower() const;
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);
        typedef enum {
            CLOSE,
            RANGE
        } rangeAttack_s;
        rangeAttack_s Range = CLOSE;
};

#endif // !CHARACTER_HPP_