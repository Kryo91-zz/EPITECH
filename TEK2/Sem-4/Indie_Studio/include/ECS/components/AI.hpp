/*
** EPITECH PROJECT, 2020
** tmp
** File description:
** AI.hpp
*/

#pragma once

namespace engine {
    struct AI
    {
        enum Direction {
            NONE = 0,
            UP,
            LEFT,
            DOWN,
            RIGHT,
            SELF
        };
        Direction dir;
    };
}