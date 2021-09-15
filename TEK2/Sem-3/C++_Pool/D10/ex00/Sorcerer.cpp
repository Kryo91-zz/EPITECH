/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
{
    this->_name = name;
    this->_title = title;
    COUT << this->_name << ", " << this->_title << ", is born!" << ENDL;
}

Sorcerer::~Sorcerer()
{
    COUT << this->_name << ", " << this->_title <<", is dead. Consequences will never be the same!" << ENDL;
}

void Sorcerer::polymorph(Victim const &sorcer) const
{
    sorcer.getPolymorphed();
}


std::ostream &operator<<(std::ostream &stream, Sorcerer &sorc)
{
    stream << "I am " << sorc.getName() << ", " << sorc.getTitle() << ", and I like ponies!" << std::endl;
    return(stream);
}

