/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** ComponentManager.hpp
*/

#pragma once

#include "lib/Lib.hpp"
#include "ECS/types.hpp"
#include "lib/std/PackedArray.hpp"

namespace ECS
{
    class ComponentManager
    {
        private:
            std::unordered_map<TypeId, ComponentType> _componentTypes{};
            std::unordered_map<TypeId, lib::shPtr<lib::IPackedArray>> _componentArrays{};
            ComponentType _nextComponentType = 0;

            template<typename T>
            lib::shPtr<lib::PackedArray<T>> getComponentArray()
            {
                TypeId typeName = typeid(T).name();

                if (_componentTypes.find(typeName) == _componentTypes.end())
                    throw lib::Exception("Component type not registered before use. " + std::string(typeName));

                return std::static_pointer_cast<lib::PackedArray<T>>(_componentArrays[typeName]);
            }

        public:
            template<typename T>
            void registerComponent(void)
            {
                TypeId typeName = typeid(T).name();

                if (_componentTypes.find(typeName) != _componentTypes.end())
                    throw lib::Exception("Component type already registered");

                _componentTypes.insert({typeName, _nextComponentType});
                _componentArrays.insert({typeName, std::make_shared<lib::PackedArray<T>>()});
                _nextComponentType++;
            }

            template<typename T>
            ComponentType getComponentType(void)
            {
                TypeId typeName = typeid(T).name();
                if (_componentTypes.find(typeName) == _componentTypes.end())
                    throw lib::Exception("Component type not registered before use. " + std::string(typeName));
                return _componentTypes[typeName];
            }

            template<typename T>
            void addComponent(Guid entity, T component)
            {
                getComponentArray<T>()->insertData(entity, component);
            }

            template<typename T>
            void removeComponent(Guid entity)
            {
                getComponentArray<T>()->removeData(entity);
            }

            template<typename T>
            T &getComponent(Guid entity)
            {
                return getComponentArray<T>()->getData(entity);
            }

            void entityDestroyed(Guid entity)
            {
                for (auto const &pair : _componentArrays) {
                    auto const &component = pair.second;

                    component->idDestroyed(entity);
                }
            }
    };
} // namespace ECS
