/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Americana
*/

#pragma once
#include "inc.hpp"
#include "Ingredients.hpp"

class americana {
    public:
        americana(int fd, std::string size, double multiplier, std::chrono::milliseconds time);
        ~americana();

    protected:
    private:
        std::chrono::duration<double, std::milli> work_time;
        std::chrono::duration<double, std::milli> restock_time;
        bool _bake;
};
