/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Toy.hpp
*/

#ifndef TOY_HPP_
    #define TOY_HPP_

    #include "../Object.hpp"

    class Toy : virtual public Object
    {
        public:
            Toy(const std::string &title);
            ~Toy();
    };

#endif