/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Object.cpp
*/

#include "Object.hpp"
#include "./toy/Teddy.hpp"
#include "./toy/LittlePony.hpp"

Object::Object(const std::string &title):
    _title(title)
{
}

Object::Object()
{}

Object::~Object()
{
}

void Object::isTaken(void) const
{
}

Object **MyUnitTests()
{
    Object **tab = new Object*[3];
    LittlePony *pony = new LittlePony("happy pony");
    Teddy *ted = new Teddy("cuddles");
    tab[0] = pony;
    tab[1] = ted;
    tab[2] = nullptr;
    return tab;
}

std::ostream &operator<<(std::ostream &s, const Object &o)
{
    s << "Object is a "<< o.getType() << " titled '" << o.getTitle() << "'" << ENDL;
    return s;
}