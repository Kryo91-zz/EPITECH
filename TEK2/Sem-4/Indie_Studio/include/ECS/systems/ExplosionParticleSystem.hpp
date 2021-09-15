/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** ExplosionParticleSystem.hpp
*/

#pragma once

#include "ECS/System.hpp"
#include "ECS/World.hpp"
#include "ECS/components/Bomb.hpp"
#include "ECS/components/Collision.hpp"
#include "ECS/components/Transform.hpp"
#include "ECS/components/Cubemap.hpp"
#include "ECS/components/ExplosionParticle.hpp"

namespace engine
{
    class ExplosionParticleSystem : public ECS::System
    {
        public:
            ExplosionParticleSystem(void);
            ~ExplosionParticleSystem(void) = default;
            void update(ECS::World &world);
            void draw(ECS::World &world);
            ECS::Signature getSignature(ECS::World &world);
        private:
            Model _model;
    };
} // namespace engine