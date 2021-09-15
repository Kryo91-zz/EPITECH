/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ControllerInputSystem.cpp
*/

#include "ECS/systems/ControllerInputSystem.hpp"

namespace engine
{
    void ControllerInputSystem::update(ECS::World &world)
    {
        for (auto &&entity : _entities) {
            auto &settings = world.getComponent<InputSettings>(entity);
            auto &inp = world.getComponent<ControllerInput>(entity);
            if (settings.AI) continue;
            if (settings.useGamepad && IsGamepadAvailable(settings.gamepadId))
                inp = {
                    IsGamepadButtonDown(settings.gamepadId, GAMEPAD_BUTTON_LEFT_FACE_UP),
                    IsGamepadButtonDown(settings.gamepadId, GAMEPAD_BUTTON_LEFT_FACE_LEFT),
                    IsGamepadButtonDown(settings.gamepadId, GAMEPAD_BUTTON_LEFT_FACE_DOWN),
                    IsGamepadButtonDown(settings.gamepadId, GAMEPAD_BUTTON_LEFT_FACE_RIGHT),
                    IsGamepadButtonPressed(settings.gamepadId, GAMEPAD_BUTTON_RIGHT_FACE_DOWN),
                    IsGamepadButtonPressed(settings.gamepadId, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT),
                };
            else
                inp = {
                    IsKeyDown(settings.up),
                    IsKeyDown(settings.left),
                    IsKeyDown(settings.down),
                    IsKeyDown(settings.right),
                    IsKeyPressed(settings.button1),
                    IsKeyPressed(settings.button2),
                };
        }
    }

    ECS::Signature ControllerInputSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<ControllerInput>());
        signature.set(world.getComponentType<InputSettings>());
        return signature;
    }
} // namespace engine
