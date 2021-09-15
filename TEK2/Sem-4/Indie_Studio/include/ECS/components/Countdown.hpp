/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Stowatch.hpp
*/

#pragma once

#include "ECS/World.hpp"

#ifndef COUNTDOWN_TYPE
    #define COUNTDOWN_TYPE "Countdown"
#endif

namespace engine
{
    struct Countdown
    {
        lib::Stopwatch sw;
    };
} // namespace engine
