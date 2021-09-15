/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD07M-corentin.petrau
** File description:
** Borg.cpp
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\nYour biological characteristics and technologies will be assimilated.\nResistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    if (this->_core != core) {
        if (this->_core)
            delete this->_core;
        this->_core = core;
    }
}

void Borg::Ship::checkCore(void)
{
    if (this->_core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}