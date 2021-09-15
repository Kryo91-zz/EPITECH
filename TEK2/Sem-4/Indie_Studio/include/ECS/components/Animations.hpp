/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Animations.hpp
*/

#pragma once

#include "stdInclude.hpp"
#include "ECS/types.hpp"

namespace engine
{
    struct Animation {
        int frameRate;
        int nbFrames;
        int currentFrame;
        float elapsedTime;
        std::vector<Model> models;
        Texture2D texture;
    };

    struct Animations {
        std::map<std::string, Animation> animations;
        std::string currentAnimation;
    };
} // namespace engine
