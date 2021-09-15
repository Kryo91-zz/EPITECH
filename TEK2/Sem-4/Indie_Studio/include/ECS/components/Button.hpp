/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Button.hpp
*/

#pragma once

#include "stdInclude.hpp"
#include "ECS/World.hpp"
#include "ECS/GameManager.hpp"

namespace engine
{
    using Event = std::function<void (ECS::World &, ECS::GameManager &)>;
    Event noEvent(void);

    struct Button {
        // Font font;
        std::string text;
        float percentX;
        float percentY;
        float size;
        Color textColor;
        Color backgroundColor;
        int returnCode;
        Event event;
    };
}
