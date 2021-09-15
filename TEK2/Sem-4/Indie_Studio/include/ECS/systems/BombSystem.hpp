/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** BombSystem.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/World.hpp"
#include "ECS/components/Bomb.hpp"
#include "ECS/components/Collision.hpp"
#include "ECS/components/Transform.hpp"
#include "ECS/components/Cubemap.hpp"
#include "ECS/components/ExplosionParticle.hpp"
#include "ECS/components/PowerUp.hpp"
#include "ECS/components/BombSettings.hpp"

namespace engine
{
    class BombSystem : public ECS::System
    {
        public:
            BombSystem(void);
            ~BombSystem(void) = default;
            void update(ECS::World &world, Cubemap &map);
            void draw(ECS::World &world, Shader *shader);
            ECS::Signature getSignature(ECS::World &world);
        private:
            Model _model;
            Model _piercingModel;
    };
} // namespace engine
