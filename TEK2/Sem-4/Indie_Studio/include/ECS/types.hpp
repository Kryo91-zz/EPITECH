/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** ECS.hpp
*/

#pragma once

#include <climits>
#include "stdInclude.hpp"

namespace ECS
{
    using Guid = unsigned int;
    using ComponentType = uint8_t;
    const Guid MAX_ENTITIES = 10000;
    const ComponentType MAX_COMPONENTS = 32;
    using Signature = std::bitset<MAX_COMPONENTS>;
    using timestep = float;
    using TypeId = const char *;
    class World;
} // namespace ECS
