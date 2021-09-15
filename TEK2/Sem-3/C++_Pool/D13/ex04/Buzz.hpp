/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD13-corentin.petrau
** File description:
** Buzz.hpp
*/

#ifndef Buzz_HPP_
    #define Buzz_HPP_


#include "Toy.hpp"

class Buzz : virtual public Toy
{
    public :
        Buzz(const std::string &name, const std::string &file = "buzz.txt");
        ~Buzz();

        void speak(const std::string &statement);
};

#endif // !Buzz_HPP_