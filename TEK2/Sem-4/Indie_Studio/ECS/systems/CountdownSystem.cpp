/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** CountdownSystem.cpp
*/

#include "ECS/systems/CountdownSystem.hpp"

namespace engine
{
    void CountdownSystem::update(ECS::World &world, ECS::timestep dt UNUSED)
    {
        std::vector<ECS::Guid> toRemove;

        for (auto &&entity : _entities) {
            auto &c = world.getComponent<Countdown>(entity);
            if (!c.sw.is_running())
                c.sw.start();
            if (c.sw.getElapsedTime() > 5)
                toRemove.push_back(entity);
        }
        for (auto &&entity : toRemove) {
            world.destroyEntity(entity);
            std::cout << "Countdown System destroyed an entity" << std::endl;
        }
    }

    ECS::Signature CountdownSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<Countdown>());
        return signature;
    }
} // namespace engine