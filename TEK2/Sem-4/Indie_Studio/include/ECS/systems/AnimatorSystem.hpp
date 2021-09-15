/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** AnimatorSystem.hpp
*/

#pragma once

#include "ECS/types.hpp"
#include "ECS/World.hpp"
#include "ECS/System.hpp"
#include "ECS/components/Animations.hpp"
#include "ECS/components/Transform.hpp"
#include "ECS/components/ControllerInput.hpp"

namespace engine
{
    struct AnimationSrc {
        std::string animationName;
        std::string folderPath;
        std::string texturePath;
    };

    class AnimatorSystem : public ECS::System
    {
        public:
            static ECS::Signature getSignature(ECS::World &world);
            void update(ECS::World &world, ECS::timestep dt);

            void addAnimation(ECS::Guid entity, ECS::World &world, AnimationSrc src, Animation anim);
            void setCurrentAnimation(ECS::Guid entity, ECS::World &world, std::string name);
            void draw(ECS::World &world, Shader *shader);
    };
} // namespace engine
