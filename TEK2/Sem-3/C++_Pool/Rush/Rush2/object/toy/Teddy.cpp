/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Teddy.cpp
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title):
    Object(title), Toy(title)
{
    this->_type = "Teddy";
}

Teddy::Teddy(const Object &obj):
    Object(obj.getTitle()), Toy(obj.getTitle())
{
    this->_type = "Teddy";
}

Teddy::~Teddy()
{
}

void Teddy::isTaken(void) const
{
    COUT << "gra hu" << ENDL;
}
