/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** EntityManager.cpp
*/

#include "ECS/managers/EntityManager.hpp"

namespace ECS
{
    EntityManager::EntityManager(void)
    {
        for (Guid entity = 0; entity < MAX_ENTITIES; entity++)
        {
            _availableEntities.push(entity);
        }
    }

    Guid EntityManager::createEntity(void)
    {
        if (_livingEntityCount >= MAX_ENTITIES)
            throw lib::Exception("Too many entities existing.");

        Guid id = _availableEntities.front();
        _availableEntities.pop();
        _livingEntityCount++;
        return id;
    }

    void EntityManager::destroyEntity(Guid entity)
    {
        if (entity >= MAX_ENTITIES)
            throw lib::Exception("Invalid entity");

        _signatures[entity].reset();
        _availableEntities.push(entity);
        _livingEntityCount--;
    }

    void EntityManager::setSignature(Guid entity, Signature signature)
    {
        if (entity >= MAX_ENTITIES)
            throw lib::Exception("Invalid entity");
        _signatures[entity] = signature;
    }

    Signature EntityManager::getSignature(Guid entity)
    {
        if (entity >= MAX_ENTITIES)
            throw lib::Exception("Invalid entity");

        return _signatures[entity];
    }
} // namespace ECS
