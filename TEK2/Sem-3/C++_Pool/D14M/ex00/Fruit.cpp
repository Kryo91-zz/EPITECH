/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-corentin.petrau
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::~Fruit() { }

Fruit &Fruit::operator=(const Fruit &rhs)
{
    this->_name = rhs._name;
    this->_vitamins = rhs._vitamins;
    return (*this);
}