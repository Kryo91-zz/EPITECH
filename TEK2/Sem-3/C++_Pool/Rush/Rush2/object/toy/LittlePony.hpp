/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** LittlePony.hpp
*/

#ifndef LITTLE_PONY_HPP_
    #define LITTLE_PONY_HPP_

    #include "Toy.hpp"

    class LittlePony : virtual public Toy
    {
    public:
        LittlePony(const std::string &title);
        LittlePony(const Object &obj);
        ~LittlePony();

        void isTaken(void) const override;
    };

#endif