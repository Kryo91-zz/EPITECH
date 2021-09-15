/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** InputSettings.hpp
*/

#pragma once

#include <raylib.h>

namespace engine
{
    struct InputSettings
    {
        bool useGamepad;
        int gamepadId;
        KeyboardKey up;
        KeyboardKey left;
        KeyboardKey down;
        KeyboardKey right;
        KeyboardKey button1;
        KeyboardKey button2;
        bool AI;
    };
} // namespace engine
