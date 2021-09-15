/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Cubemap.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/World.hpp"
#include "ECS/components/Transform.hpp"
#include "ECS/components/Cubemap.hpp"

namespace engine
{
    class CubemapSystem : public ECS::System
    {
        public:
            CubemapSystem(void) = default;
            ~CubemapSystem(void) = default;
            Cubemap createCubemap(std::string);
            void draw(ECS::World &world, Shader *shader);
            ECS::Signature getSignature(ECS::World &world);
        private:
            Model _modelPower;
            Model _modelPiercing;
            Model _modelLifePlus;
            Model _modelLifeMinus;
            Model _modelBombPlus;
    };
}