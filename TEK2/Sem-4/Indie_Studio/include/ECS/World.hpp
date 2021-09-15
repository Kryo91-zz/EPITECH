/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** World.hpp
*/

#pragma once

#include "stdInclude.hpp"
#include "lib/Lib.hpp"
#include "types.hpp"
#include "System.hpp"
#include "lib/std/DLLoader.hpp"
#include "ECS/managers/ComponentManager.hpp"
#include "ECS/managers/EntityManager.hpp"
#include "ECS/managers/SystemManager.hpp"

namespace ECS
{
    class World
    {
        private:
            std::unique_ptr<ComponentManager> _componentManager;
            std::unique_ptr<EntityManager> _entityManager;
            std::unique_ptr<SystemManager> _systemManager;
            bool _stop = false;
        public:
            World(void) = default;
            ~World(void) = default;
            void init(void);
            void reset(void);

            // Entity methods
            Guid createEntity(void);
            void destroyEntity(Guid entity);

            // Component methods
            template<typename T>
            void registerComponent()
            {
                _componentManager->registerComponent<T>();
            }

            template<typename T>
            void addComponent(Guid entity, T component)
            {
                _componentManager->addComponent<T>(entity, component);

                auto signature = _entityManager->getSignature(entity);
                signature.set(_componentManager->getComponentType<T>(), true);
                _entityManager->setSignature(entity, signature);

                _systemManager->entitySignatureChanged(entity, signature);
            }

            template<typename T>
            void removeComponent(Guid entity)
            {
                _componentManager->removeComponent<T>(entity);

                auto signature = _entityManager->getSignature(entity);
                signature.set(_componentManager->getComponentType<T>(), false);
                _entityManager->setSignature(entity, signature);

                _systemManager->entitySignatureChanged(entity, signature);
            }

            template<typename T>
            T& getComponent(Guid entity)
            {
                return _componentManager->getComponent<T>(entity);
            }

            template<typename T>
            ComponentType getComponentType()
            {
                return _componentManager->getComponentType<T>();
            }


            // System methods
            template<typename T>
            std::shared_ptr<T> registerSystem()
            {
                return _systemManager->registerSystem<T>();
            }

            template<typename T>
            void setSystemSignature(Signature signature)
            {
                _systemManager->setSignature<T>(signature);
            }
    };

} // namespace ECS
