/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** CollisionSystem.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/World.hpp"
#include "ECS/components/ControllerInput.hpp"
#include "ECS/components/Transform.hpp"
#include "ECS/components/Collision.hpp"
#include "ECS/components/BombSettings.hpp"

namespace engine
{
    class CollisionSystem : public ECS::System
    {
        public:
            CollisionSystem(void) = default;
            ~CollisionSystem(void) = default;
            void update(ECS::World &world, std::array<std::array<int, 16>, 16> &map);
            ECS::Signature getSignature(ECS::World &world);
    };
} // namespace engine

