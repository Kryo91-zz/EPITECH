/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ControllerInput.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/World.hpp"
#include "ECS/components/ControllerInput.hpp"
#include "ECS/components/InputSettings.hpp"

namespace engine
{
    class ControllerInputSystem : public ECS::System
    {
        public:
            ControllerInputSystem(void) = default;
            ~ControllerInputSystem(void) = default;
            void update(ECS::World &world);
            ECS::Signature getSignature(ECS::World &world);
    };
} // namespace engine
