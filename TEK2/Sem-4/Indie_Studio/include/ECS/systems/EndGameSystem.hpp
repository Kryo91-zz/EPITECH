/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** EndGameSystem.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/GameManager.hpp"
#include "ECS/World.hpp"
#include "ECS/components/PlayerStat.hpp"
#include "ECS/components/InputSettings.hpp"

namespace engine
{
    class EndGameSystem : public ECS::System
    {
        public:
            EndGameSystem(void) = default;
            ~EndGameSystem(void) = default;
            void update(ECS::World &world, ECS::GameManager &gm);
            ECS::Signature getSignature(ECS::World &world);
    };
} // namespace engine
