/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Bomb.hpp
*/

#pragma once

#include "ECS/types.hpp"

namespace engine
{
    struct Bomb
    {
        int lifetime;
        int power;
        bool piercing;
        ECS::Guid parent;
    };
} // namespace engine
