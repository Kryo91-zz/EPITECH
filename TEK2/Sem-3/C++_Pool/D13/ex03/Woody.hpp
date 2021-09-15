/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD13-corentin.petrau
** File description:
** Woody.hpp
*/

#ifndef Woody_HPP_
    #define Woody_HPP_


#include "Toy.hpp"

class Woody : virtual public Toy
{
    public :
        Woody(const std::string &name, const std::string &file = "woody.txt");
        ~Woody();

        void speak(const std::string &statement);
};

#endif // !Woody_HPP_