/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Toy.hpp
*/

#ifndef TOYH
#define TOYH

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Picture.hpp"

class Toy
{
    public:
        typedef enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        Toy();
        Toy(ToyType type, std::string const &name, std::string const &picture);
        ~Toy();

        int getType() const {return this->_type;};
        std::string const &getName() const {return this->_name;};
        std::string const &getAscii() const {return this->_picture.data;};

        void setName(std::string const &name) {this->_name = name;};
        void setAscii(std::string const &picture) {this->_picture.getPictureFromFile(picture);};

    protected:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif