/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-corentin.petrau
** File description:
** Fruit.hpp
*/

#ifndef FRUIT_HPP_
    #define FRUIT_HPP_
    #define COUT std::cout
    #define ENDL std::endl

#include <ostream>
#include <iostream>


class Fruit
{
    public :
        virtual ~Fruit() = 0;

        std::string getName() {return this->_name;};
        int getVitamins() {return this->_vitamins;};

        Fruit &operator=(const Fruit &rhs);

        int _vitamins;
        std::string _name;
};

#endif // !FRUIT_HPP_
