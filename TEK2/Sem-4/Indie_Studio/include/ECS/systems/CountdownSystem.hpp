/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** CountdownSystem.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/components/Countdown.hpp"

namespace engine
{
    class CountdownSystem : public ECS::System
    {
        public:
            static ECS::Signature getSignature(ECS::World &world);
            void update(ECS::World &world, ECS::timestep dt);
    };
} // namespace engine
