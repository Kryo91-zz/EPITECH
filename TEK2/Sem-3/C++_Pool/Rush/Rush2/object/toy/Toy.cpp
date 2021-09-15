/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy(const std::string &title):
    Object(title)
{
    this->_type = "Toy";
}

Toy::~Toy()
{
}