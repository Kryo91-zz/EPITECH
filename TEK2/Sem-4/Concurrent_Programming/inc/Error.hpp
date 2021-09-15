/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Error
*/

#pragma once
#include "inc.hpp"

class Error {
    public:
        Error(int nb, char **tab);
        ~Error();

    protected:
    private:
        double _cooking_time_multiplier;
        size_t _nb_cooks;
        std::chrono::milliseconds _time;
};
