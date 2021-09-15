/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Button.hpp
*/

#pragma once

#include "stdInclude.hpp"
#include "ECS/components/Button.hpp"
#include "ECS/systems/MouseInputSystem.hpp"
#include "ECS/System.hpp"

namespace engine
{
    class ButtonSystem : public ECS::System
    {
        public:
            static ECS::Signature getSignature(ECS::World &world);
            void update(ECS::World &world, ECS::GameManager &gm);

            Rectangle getButtonRectangle(Button &b);
            bool isHovered(Button &b, MouseInput &m);
            bool isClicked(Button &b, MouseInput &m);
            void draw(ECS::World &world);
    };
}
