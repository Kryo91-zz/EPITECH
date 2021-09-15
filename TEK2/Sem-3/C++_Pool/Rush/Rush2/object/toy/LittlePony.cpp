/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** LittlePony.cpp
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title):
    Object(title), Toy(title)
{
    this->_type = "LittlePony";
}

LittlePony::LittlePony(const Object &obj):
    Object(obj.getTitle()), Toy(obj.getTitle())
{
    this->_type = "LittlePony";
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken(void) const
{
    COUT << "yo man" << ENDL;
}