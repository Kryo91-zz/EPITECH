/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD10-lyvia.mallereau
** File description:
** Character.hpp
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
    protected:
        std::string _name;
        int _hp;
        int _ap;
        AWeapon *_weapon = nullptr;
    public:
        Character(std::string const &name);
        ~Character();
        std::string const &getName() const {return this->_name;};
        int getAP() const {return this->_ap;};
        void equip(AWeapon *weapon) {this->_weapon = weapon;};
        AWeapon *getWeapon() const  {return this->_weapon;};
        void recoverAP();
        void attack(AEnemy *enemy);
};

std::ostream &operator<<(std::ostream &stream, Character const &caract);

#endif