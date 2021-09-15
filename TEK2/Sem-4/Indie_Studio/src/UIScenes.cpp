/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** UIScenes.cpp
*/

#include "stdInclude.hpp"
#include "lib/Lib.hpp"
#include "ECS/GameManager.hpp"
#include "ECS/components/Collision.hpp"
#include "ECS/components/Cubemap.hpp"
#include "ECS/components/ControllerInput.hpp"
#include "ECS/components/InputSettings.hpp"
#include "ECS/components/PlayerStat.hpp"
#include "ECS/systems/CountdownSystem.hpp"
#include "ECS/systems/AnimatorSystem.hpp"
#include "ECS/systems/ButtonSystem.hpp"
#include "ECS/systems/CollisionSystem.hpp"
#include "ECS/systems/CubemapSystem.hpp"
#include "ECS/systems/MouseInputSystem.hpp"
#include "ECS/systems/ControllerInputSystem.hpp"
#include "ECS/systems/BombSystem.hpp"
#include "ECS/systems/PlayerBombSystem.hpp"
#include "ECS/systems/ExplosionParticleSystem.hpp"
#include "ECS/systems/EndGameSystem.hpp"
#include "globalScope.hpp"

static void drawTextWinner(std::string winnerName)
{
    float fontSize = 50.0f;
    const int borderHeight = 20.0f;

    std::string text = (winnerName);
    float size = static_cast<float>(MeasureText(text.c_str(), fontSize));
    float posX = 0.5f * WINDOW_WIDTH - size * 0.5f;
    float posY = 0.15f * WINDOW_HEIGHT;

    Rectangle rect = {
        0.0f,
        posY - borderHeight * 0.5f,
        WINDOW_WIDTH,
        fontSize + borderHeight
    };

    DrawRectangleRec(rect, WHITE);
    DrawText(text.c_str(), posX, posY, fontSize, GREEN);
}

int sceneMenu(ECS::World &world, ECS::GameManager &gm)
{
    Texture2D background = LoadTexture("resources/godzilla-vs-kong-cover.png");

    world.registerComponent<engine::Transform>();
    world.registerComponent<engine::MouseInput>();
    world.registerComponent<engine::Button>();

    auto mouseInputSystem = world.registerSystem<engine::MouseInputSystem>();
    world.setSystemSignature<engine::MouseInputSystem>(mouseInputSystem->getSignature(world));

    auto buttonSystem = world.registerSystem<engine::ButtonSystem>();
    world.setSystemSignature<engine::ButtonSystem>(buttonSystem->getSignature(world));

    auto buttonPlay = world.createEntity();
    world.addComponent(buttonPlay, engine::MouseInput());
    world.addComponent(buttonPlay, engine::Button({"Play", 0.5f, 0.35f, 70.0f, WHITE, GREEN, ECS::GameManager::NEXT, engine::noEvent()}));

    auto buttonQuit = world.createEntity();
    world.addComponent(buttonQuit, engine::MouseInput());
    world.addComponent(buttonQuit, engine::Button({"Quit", 0.5f, 0.65f, 70.0f, WHITE, GREEN, ECS::GameManager::QUIT, engine::noEvent()}));

    lib::Stopwatch sw;
    sw.start();
    for (; !WindowShouldClose() && !gm.shouldStop();) {
        BeginDrawing();
        ClearBackground({10, 20, 60, 255});

        mouseInputSystem->update(world);
        buttonSystem->update(world, gm);

        DrawTextureNPatch(
            background,
            {Rectangle({0, 0, float(background.width), float(background.height)})},
            Rectangle({0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}), {0,0}, 0.0f, WHITE);
        buttonSystem->draw(world);
        drawTextWinner("Godzilla vs Kong");

        // DrawFPS(10, 10); // DEBUG
        EndDrawing();
    }
    return (gm.returnCode());
}

int sceneEnd(ECS::World &world, ECS::GameManager &gm)
{
    Texture2D background = LoadTexture("resources/godzilla-vs-kong-cover.png");
    std::string winnerName = gm.getSharedState<std::string>();

    world.registerComponent<engine::Transform>();
    world.registerComponent<engine::MouseInput>();
    world.registerComponent<engine::Button>();

    auto mouseInputSystem = world.registerSystem<engine::MouseInputSystem>();
    world.setSystemSignature<engine::MouseInputSystem>(mouseInputSystem->getSignature(world));

    auto buttonSystem = world.registerSystem<engine::ButtonSystem>();
    world.setSystemSignature<engine::ButtonSystem>(buttonSystem->getSignature(world));

    auto buttonPlay = world.createEntity();
    world.addComponent(buttonPlay, engine::MouseInput());
    world.addComponent(buttonPlay, engine::Button({"Restart", 0.5f, 0.35f, 70.0f, WHITE, GREEN, 1, engine::noEvent()}));

    auto buttonQuit = world.createEntity();
    world.addComponent(buttonQuit, engine::MouseInput());
    world.addComponent(buttonQuit, engine::Button({"Quit", 0.5f, 0.65f, 70.0f, WHITE, GREEN, ECS::GameManager::QUIT, engine::noEvent()}));

    lib::Stopwatch sw;
    sw.start();
    for (; !WindowShouldClose() && !gm.shouldStop();) {
        BeginDrawing();
        ClearBackground({10, 20, 60, 255});

        mouseInputSystem->update(world);
        buttonSystem->update(world, gm);

        DrawTextureNPatch(
            background,
            {Rectangle({0, 0, float(background.width), float(background.height)})},
            Rectangle({0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}), {0,0}, 0.0f, WHITE);
        buttonSystem->draw(world);

        drawTextWinner(winnerName + std::string(" won !"));

        // DrawFPS(10, 10); // DEBUG
        EndDrawing();
    }
    return (gm.returnCode());
}

static engine::Event setupEvent(int nbPlayers)
{
    return ([nbPlayers](ECS::World &_ UNUSED, ECS::GameManager &gm) {
        gm.getSharedState<PlayerSetup>().nb = nbPlayers;
    });
}

int sceneSetup(ECS::World &world, ECS::GameManager &gm)
{
    Texture2D background = LoadTexture("resources/godzilla-vs-kong-cover.png");

    world.registerComponent<engine::Transform>();
    world.registerComponent<engine::MouseInput>();
    world.registerComponent<engine::Button>();

    auto mouseInputSystem = world.registerSystem<engine::MouseInputSystem>();
    world.setSystemSignature<engine::MouseInputSystem>(mouseInputSystem->getSignature(world));

    auto buttonSystem = world.registerSystem<engine::ButtonSystem>();
    world.setSystemSignature<engine::ButtonSystem>(buttonSystem->getSignature(world));

    auto button1P = world.createEntity();
    world.addComponent(button1P, engine::MouseInput());
    world.addComponent(button1P, engine::Button({"1P", 0.25f, 0.25f, 30.0f, WHITE, GREEN, 2, setupEvent(1)}));

    auto button2P = world.createEntity();
    world.addComponent(button2P, engine::MouseInput());
    world.addComponent(button2P, engine::Button({"2P", 0.75f, 0.25f, 30.0f, WHITE, GREEN, 2, setupEvent(2)}));

    auto button3P = world.createEntity();
    world.addComponent(button3P, engine::MouseInput());
    world.addComponent(button3P, engine::Button({"3P", 0.25f, 0.75f, 30.0f, WHITE, GREEN, 2, setupEvent(3)}));

    auto button4P = world.createEntity();
    world.addComponent(button4P, engine::MouseInput());
    world.addComponent(button4P, engine::Button({"4P", 0.75f, 0.75f, 30.0f, WHITE, GREEN, 2, setupEvent(4)}));

    lib::Stopwatch sw;
    sw.start();
    for (; !WindowShouldClose() && !gm.shouldStop();) {
        BeginDrawing();
        ClearBackground({10, 20, 60, 255});

        mouseInputSystem->update(world);
        buttonSystem->update(world, gm);

        DrawTextureNPatch(
            background,
            {Rectangle({0, 0, float(background.width), float(background.height)})},
            Rectangle({0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}), {0,0}, 0.0f, WHITE);
        buttonSystem->draw(world);

        // DrawFPS(10, 10); // DEBUG
        EndDrawing();
    }
    return (gm.returnCode());
}