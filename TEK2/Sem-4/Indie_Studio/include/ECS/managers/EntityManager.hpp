/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** EntityManager.hpp
*/

#pragma once

#include "lib/Lib.hpp"
#include "ECS/types.hpp"

namespace ECS
{

class EntityManager
{
    private:
        std::queue<Guid> _availableEntities {};
        std::array<Signature, MAX_ENTITIES> _signatures {};
        uint32_t _livingEntityCount = 0;
    public:
        EntityManager(void);
        Guid createEntity(void);
        void destroyEntity(Guid entity);
        void setSignature(Guid entity, Signature signature);
        Signature getSignature(Guid entity);
    };


} // namespace ECS
