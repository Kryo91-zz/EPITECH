/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** System.cpp
*/

#include "ECS/managers/SystemManager.hpp"
#include "ECS/World.hpp"

namespace ECS
{
    void SystemManager::entityDestroyed(Guid entity)
    {
        for (auto const &pair : _systems) {
            auto const &system = pair.second;
            system->_entities.erase(entity);
        }
    }

    void SystemManager::entitySignatureChanged(Guid entity, Signature entitySignature)
    {
        for (auto const &pair : _systems) {
            auto const &type = pair.first;
            auto const &system = pair.second;
            auto const &systemSignature = _signatures[type];

            if ((entitySignature & systemSignature) == systemSignature) {
                system->_entities.insert(entity);
            } else {
                system->_entities.erase(entity);
            }
        }
    }
} // namespace ECS
