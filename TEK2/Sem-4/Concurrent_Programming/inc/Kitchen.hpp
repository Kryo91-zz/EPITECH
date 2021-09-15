/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Kitchen.hpp
*/

#pragma once

#include "inc.hpp"
#include "Ingredients.hpp"

class Kitchen
{
    private:
        int nb_commands;
        double _cooking_time_multiplier;
        size_t _nb_cooks;
        std::chrono::milliseconds _time;
        std::chrono::duration<double, std::milli> work_time;
        std::chrono::duration<double, std::milli> restock_time;
        Ingredients ing;
        int _fd;
        struct sockaddr_un _addr;
        int len;

    public:
        Kitchen(double multiplier, size_t nb_cook, std::chrono::milliseconds time);
        Kitchen();
        ~Kitchen() {};
        void cooking(std::string pizza, std::string size);

        enum PizzaType
        {
            Regina = 1,
            Margarita = 2,
            Americana = 4,
            Fantasia = 8
        };

        enum PizzaSize
        {
            S = 1,
            M = 2,
            L = 4,
            XL = 8,
            XXL = 16
        };
};