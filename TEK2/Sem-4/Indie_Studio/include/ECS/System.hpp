/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** System.hpp
*/

#pragma once

#include "lib/Lib.hpp"
#include "types.hpp"

namespace ECS
{
    class System
    {
        public:
            std::set<Guid> _entities;
    };
}