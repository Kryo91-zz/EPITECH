/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Teddy.hpp
*/

#ifndef TEDDY_HPP_
    #define TEDDY_HPP_

    #include "Toy.hpp"

    class Teddy : virtual public Toy
    {
    public:
        Teddy(const std::string &title);
        Teddy(const Object &obj);
        ~Teddy();

        void isTaken(void) const override;
    };

#endif