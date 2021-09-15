/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Transform.hpp
*/

#pragma once

#include "stdInclude.hpp"

namespace engine
{
    struct Transform {
        Vector3 position;
        Vector3 rotation;
        float scale;
    };
} // namespace engine
