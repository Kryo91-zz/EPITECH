/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** World.cpp
*/

#include "ECS/World.hpp"

namespace ECS
{
    void World::init(void)
    {
        _componentManager = std::make_unique<ComponentManager>();
        _entityManager = std::make_unique<EntityManager>();
        _systemManager = std::make_unique<SystemManager>();
    }

    Guid World::createEntity(void)
    {
        return _entityManager->createEntity();
    }

    void World::destroyEntity(Guid entity)
    {
        _entityManager->destroyEntity(entity);
        _componentManager->entityDestroyed(entity);
        _systemManager->entityDestroyed(entity);
    }

    void World::reset(void)
    {
        this->init();
    }

} // namespace ECS
