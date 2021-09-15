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
            ALIEN,
            WOODY,
            BUZZ
        };

        Toy();
        Toy(const Toy &other);
        Toy(ToyType type, std::string const &name, std::string const &picture);
        virtual ~Toy();

        int getType() const {return this->_type;};
        virtual std::string const &getName() const {return this->_name;};
        virtual std::string const &getAscii() const {return this->_picture.data;};

        void setName(std::string const &name) {this->_name = name;};
        void setAscii(std::string const &picture) {this->_picture.getPictureFromFile(picture);};

        Toy &operator=(const Toy &other);

    protected:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif