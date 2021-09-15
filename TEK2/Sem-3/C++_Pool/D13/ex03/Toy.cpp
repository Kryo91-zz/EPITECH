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

Toy::Toy(const Toy &other) :
    _type(other._type), _name(other._name), _picture(other._picture) { }

Toy::~Toy() { }

Toy &Toy::operator=(const Toy &other)
{
    this->_name = other._name;
    this->_type = other._type;
    this->_picture = other._picture;
    return(*this);
}

void Toy::speak(const std::string &statement)
{
    COUT << this->_name << " \"" << statement << "\"" << ENDL;
}