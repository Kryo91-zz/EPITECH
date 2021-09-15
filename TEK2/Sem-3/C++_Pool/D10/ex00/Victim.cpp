/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(const std::string &name)
{
    this->_name = name;

    COUT << "Some random victim called " << this->_name << " just popped!" << ENDL;
}

Victim::~Victim()
{
    COUT << "Victim " << this->_name << " just died for no apparent reason!" << ENDL;
}

void Victim::getPolymorphed() const
{
    COUT << this->_name << " has been turned into a cute little sheep!" << ENDL;
}

std::ostream &operator<<(std::ostream &stream, Victim &vict)
{
    stream << "I'm " << vict.getName() << " and I like otters!" << std::endl;
    return(stream);
}