/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** BombSettings.hpp
*/

#pragma once

namespace engine
{
    struct BombSettings
    {
        int lifetimeBuff;
        int power;
        bool piercing;
        int nbBombs;
    };
} // namespace engine