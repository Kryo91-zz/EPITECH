/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** PowerUp.hpp
*/

#pragma once


namespace engine
{

    struct PowerUp
    {
        enum Type
        {
            POWERUP,
            PIERCING,
            LIFETIMEPLUS,
            LIFETIMEMINUS
        };
        Type type;
        bool isDead;
        float rotation;
    };
} // namespace engine
