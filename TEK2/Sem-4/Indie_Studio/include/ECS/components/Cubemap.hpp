/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Cubemap.hpp
*/

#pragma once

#include "stdInclude.hpp"

namespace engine
{
    struct Cubemap {
        enum CellTypes {
            FLOOR,
            INDESTRUCTIBLE,
            DESTRUCTIBLE,
            DANGER,
            POWER_PLUS,
            PIERCING,
            PLUS_LIFE,
            MINUS_LIFE,
            BOMBS_PLUS,
            BOMB
        };
        Model model;
        Texture2D texture;
        std::array<std::array<int, 16>, 16> collision;
        Model blockModel;
    };

} // namespace engine