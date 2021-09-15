/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ControllerInput.hpp
*/

#pragma once

#include <raylib.h>

namespace engine
{
    struct ControllerInput {
        bool up;
        bool left;
        bool down;
        bool right;
        bool button1;
        bool button2;
    };
} // namespace engine
