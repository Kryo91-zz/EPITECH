/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Ingredients
*/

#pragma once
#include "inc.hpp"

class Ingredients
{
    public:
        Ingredients() {};
        ~Ingredients() {};
        void restock();
        bool margarita();
        bool fantasia();
        bool americana();
        bool regina();
        bool check_margarita();
        bool check_fantasia();
        bool check_americana();
        bool check_regina();

    private:
        int doe = 5;
        int tomatoe = 5;
        int goat = 5;
        int ham = 5;
        int gruyere = 5;
        int mushrooms = 5;
        int steak = 5;
        int eggplant = 5;
};
