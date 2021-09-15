/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{
    this->_picture.data = "";
}

Toy::Toy(ToyType type, std::string const &name, std::string const &ascii) : 
    _type(type), _name(name), _picture(ascii) { }

Toy::~Toy() { }