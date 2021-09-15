/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** PlayerBombSystem.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/World.hpp"
#include "ECS/components/Bomb.hpp"
#include "ECS/components/Collision.hpp"
#include "ECS/components/Transform.hpp"
#include "ECS/components/ControllerInput.hpp"
#include "ECS/components/BombSettings.hpp"
#include "ECS/components/PlayerStat.hpp"

namespace engine
{
    class PlayerBombSystem : public ECS::System
    {
        public:
            PlayerBombSystem(void) = default;
            ~PlayerBombSystem(void) = default;
            void update(ECS::World &world, Cubemap &map);
            ECS::Signature getSignature(ECS::World &world);
    };
} // namespace engine
