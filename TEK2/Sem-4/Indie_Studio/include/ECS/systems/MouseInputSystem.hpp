/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** InputSystem.hpp
*/

#pragma once

#include "ECS/World.hpp"
#include "ECS/System.hpp"
#include "ECS/types.hpp"
#include "ECS/components/MouseInput.hpp"

namespace engine
{
    // The input system just fills in every Input component with the input of the current frame so that it is accessible to every other system
    class MouseInputSystem : public ECS::System
    {
        public:
            MouseInputSystem(void) = default;
            ~MouseInputSystem(void) = default;
            void update(ECS::World &world);
            ECS::Signature getSignature(ECS::World &world);
        private:
            std::shared_ptr<GlobalMouseInput> _gInput = std::make_shared<GlobalMouseInput>();
    };
} // namespace engine
