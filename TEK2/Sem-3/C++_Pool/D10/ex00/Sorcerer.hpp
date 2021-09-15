/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#define COUT std::cout
#define ENDL std::endl

#include <ostream>
#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{
    public:
        Sorcerer(const std::string &name, const std::string &title);
        ~Sorcerer();
        std::string getName() {return this->_name;};
        std::string getTitle() {return this->_title;};
        void polymorph(Victim const &sorcer) const;

    protected:
        std::string _name;
        std::string _title;

};
std::ostream &operator<<(std::ostream &stream, Sorcerer &sorc);

#endif /* !SORCERER_HPP_ */
