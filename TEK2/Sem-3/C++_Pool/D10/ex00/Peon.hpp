/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : virtual public Victim
{
    public:
        Peon(const std::string &name);
        ~Peon();
        void getPolymorphed() const;

    protected:
        std::string _name;
};

std::ostream &operator<<(std::ostream &stream, Peon &peon);

#endif /* !PEON_HPP_ */
