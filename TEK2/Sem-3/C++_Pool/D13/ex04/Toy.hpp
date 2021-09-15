/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Toy.hpp
*/

#ifndef TOYH
#define TOYH

#define COUT std::cout
#define ENDL std::endl


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
        std::string const &getName() const {return this->_name;};
        std::string const &getAscii() const {return this->_picture.data;};

        void setName(std::string const &name) {this->_name = name;};
        void setAscii(std::string const &picture) {this->_picture.getPictureFromFile(picture);};

        virtual void speak(const std::string &statement);

        Toy &operator=(const Toy &other);
        Toy &operator<<(const std::string &message);

    protected:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

std::ostream &operator<<(const std::ostream *s, const Toy &toy);

#endif