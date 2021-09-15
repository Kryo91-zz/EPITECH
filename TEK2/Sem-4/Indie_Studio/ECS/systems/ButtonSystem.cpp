/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** ButtonSystem.cpp
*/

#include "stdInclude.hpp"
#include "ECS/GameManager.hpp"
#include "globalScope.hpp"
#include "ECS/systems/ButtonSystem.hpp"

namespace engine
{
    Event noEvent(void) { return [](ECS::World &, ECS::GameManager &){}; }

    void ButtonSystem::update(ECS::World &world, ECS::GameManager &gm)
    {
        for (auto &&entity : _entities) {
            auto &b = world.getComponent<Button>(entity);
            auto &m = world.getComponent<MouseInput>(entity);

            if (isClicked(b, m)) {
                gm.setReturnCode(b.returnCode);
                b.event(world, gm);
                gm.stop();
            }
        }
    }

    bool ButtonSystem::isHovered(Button &b, MouseInput &m)
    {
        Rectangle rect = getButtonRectangle(b);

        if (CheckCollisionPointRec({m.gInput->mousePosition.x, m.gInput->mousePosition.y}, rect))
            return true;
        return false;
    }

    bool ButtonSystem::isClicked(Button &b, MouseInput &m)
    {
        Rectangle rect = getButtonRectangle(b);

        if (m.gInput->leftClick)
            if (CheckCollisionPointRec({m.gInput->mousePosition.x, m.gInput->mousePosition.y}, rect))
                return true;
        return false;
    }

    Rectangle ButtonSystem::getButtonRectangle(Button &b)
    {
        ViewportSettings &vs = getViewportSettings();

        float size = static_cast<float>(MeasureText(b.text.c_str(), b.size));
        float posX = b.percentX * vs.width - size * 0.5f;
        float posY = b.percentY * vs.height;

        const int borderWidth = 175.0f;
        const int borderHeight = 20.0f;

        // Font font = GetFontDefault();
        // const int defaultFontSize = 10;   // Default Font chars height in pixel
        // const int spacing = b.size / defaultFontSize;
        // Vector2 textSize = MeasureTextEx(font, b.text.c_str(), defaultFontSize, spacing);

        Rectangle rect = {
            posX - borderWidth * 0.5f,
            posY - borderHeight * 0.5f,
            size + borderWidth,
            b.size + borderHeight
        };

        return rect;
    }

    void ButtonSystem::draw(ECS::World &world)
    {
        ViewportSettings &vs = getViewportSettings();

        for (auto &&entity : _entities) {
            auto &b = world.getComponent<Button>(entity);
            auto &m = world.getComponent<MouseInput>(entity);

            float size = static_cast<float>(MeasureText(b.text.c_str(), b.size));
            float posX = b.percentX * vs.width - size * 0.5f;
            float posY = b.percentY * vs.height;
            Rectangle rect = getButtonRectangle(b);

            if (isHovered(b, m)) {
                b.backgroundColor.a = 255;
                DrawRectangleRounded(rect, 0.2f, 4, b.backgroundColor);
                DrawText(b.text.c_str(), posX, posY, b.size, b.textColor);
            } else {
                b.backgroundColor.a = 180;
                DrawRectangleRounded(rect, 0.2f, 4, b.backgroundColor);
                DrawText(b.text.c_str(), posX, posY, b.size, b.textColor);
            }
        }
    }

    ECS::Signature ButtonSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<engine::Button>());
        signature.set(world.getComponentType<engine::MouseInput>());
        return signature;
    }
}
