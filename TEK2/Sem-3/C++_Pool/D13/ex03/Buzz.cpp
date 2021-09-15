/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD13-corentin.petrau
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) :
        Toy(BUZZ, name, file) { };

Buzz::~Buzz() { }

void Buzz::speak(const std::string &statement)
{
    COUT << "BUZZ: " << this->_name << " \"" << statement << "\"" << ENDL;
}