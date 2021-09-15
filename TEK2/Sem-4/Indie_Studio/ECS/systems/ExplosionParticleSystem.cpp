/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** ExplosionParticleSystem.cpp
*/

#include "ECS/systems/ExplosionParticleSystem.hpp"

namespace engine
{
    ExplosionParticleSystem::ExplosionParticleSystem(void)
    {
        _model = LoadModel("Default cube");
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/explosionTexture.png");
    }

    ECS::Signature ExplosionParticleSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<engine::Transform>());
        signature.set(world.getComponentType<ExplosionParticle>());
        return signature;
    }

    void ExplosionParticleSystem::draw(ECS::World &world)
    {
        BeginBlendMode(BLEND_ADDITIVE);
        for (auto &&entity : _entities) {
            auto &particle = world.getComponent<ExplosionParticle>(entity);
            auto &tr = world.getComponent<engine::Transform>(entity);
            
            DrawModel(_model, tr.position, 1, particle.color);
        }
        EndBlendMode();
    }

    void ExplosionParticleSystem::update(ECS::World &world)
    {
        std::vector<ECS::Guid> toRemove;

        for (auto &&entity : _entities) {
            auto &particle = world.getComponent<ExplosionParticle>(entity);
            particle.alpha -= 5;
            particle.color.a = particle.alpha;
            if (particle.alpha <= 0)
                toRemove.push_back(entity);
        }
        for (auto &&entity : toRemove) {
            world.destroyEntity(entity);
        }
    }
} // namespace engine
