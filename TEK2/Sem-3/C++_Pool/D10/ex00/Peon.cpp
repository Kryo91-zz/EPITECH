/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** Peon
*/

#include "Peon.hpp"

Peon::Peon(const std::string &name):
    Victim(name), _name(name)
{
    COUT << "Zog zog." << ENDL;
}

Peon::~Peon()
{
    COUT << "Bleuark..." << ENDL;
}

void Peon::getPolymorphed() const
{
    COUT << this->_name << " has been turned into a pink pony!" << ENDL;
}

std::ostream &operator<<(std::ostream &stream, Peon &peon)
{
    stream << "I'm " << peon.getName() << " and I like otters!" << std::endl;
    return(stream);
}