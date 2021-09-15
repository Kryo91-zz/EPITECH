/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** InputSystem.cpp
*/

#include "ECS/systems/MouseInputSystem.hpp"

namespace engine
{
    void MouseInputSystem::update(ECS::World &world)
    {
        _gInput->leftClick = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        _gInput->rightClick = IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
        _gInput->mousePosition = GetMousePosition();

        // Setting MouseInput component pointer to collected input if it wasn't
        for (auto &&entity : _entities) {
            MouseInput &c = world.getComponent<MouseInput>(entity);
            if (c.gInput != _gInput)
                c.gInput = _gInput;
        }
    }

    ECS::Signature MouseInputSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<MouseInput>());
        return signature;
    }
} // namespace engine
