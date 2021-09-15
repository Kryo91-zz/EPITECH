/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** main.cpp
*/

#include <iostream>

#include <raylib.h>
#include "raymath.h"

#define RLIGHTS_IMPLEMENTATION
#include "rlights.hpp"

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
#include "ECS/systems/AISystem.hpp"
#include "scenes.hpp"
#include "globalScope.hpp"

// #define DEBUG

Camera3D setupCamera(void)
{
    Camera3D camera = {
        { 7.0f, 20.0f, 7.0f },
        // .position={ 7.0f, 18.0f, 15.0f },
        { 7.0f, 0.0f, 7.0f },

        { 0.0f, 1.0f, 0.0f },
        45.0f,
        CAMERA_PERSPECTIVE
    };

    SetCameraMode(camera, CAMERA_FREE);

    return camera;
}

void initWindow(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bomberman");
    setViewportSettings(WINDOW_WIDTH, WINDOW_HEIGHT);
    SetTargetFPS(60);
}

int mainGame(ECS::World &world, ECS::GameManager &gm)
{
    int nbPlayers = gm.getSharedState<PlayerSetup>().nb;
    Camera3D camera = setupCamera();

    world.registerComponent<engine::Transform>();
    world.registerComponent<engine::ControllerInput>();
    world.registerComponent<engine::InputSettings>();
    world.registerComponent<engine::Animations>();
    world.registerComponent<engine::PlayerStat>();
    world.registerComponent<engine::Cubemap>();
    world.registerComponent<engine::Collision>();
    world.registerComponent<engine::Bomb>();
    world.registerComponent<engine::BombSettings>();
    world.registerComponent<engine::ExplosionParticle>();
    world.registerComponent<engine::PowerUp>();
    world.registerComponent<engine::AI>();

    auto endSystem = world.registerSystem<engine::EndGameSystem>();
    world.setSystemSignature<engine::EndGameSystem>(endSystem->getSignature(world));
    auto aiSystem = world.registerSystem<engine::AISystem>();
    world.setSystemSignature<engine::AISystem>(aiSystem->getSignature(world));
    auto animSystem = world.registerSystem<engine::AnimatorSystem>();
    world.setSystemSignature<engine::AnimatorSystem>(animSystem->getSignature(world));
    auto cubemapSystem = world.registerSystem<engine::CubemapSystem>();
    world.setSystemSignature<engine::CubemapSystem>(cubemapSystem->getSignature(world));
    auto controllerSystem = world.registerSystem<engine::ControllerInputSystem>();
    world.setSystemSignature<engine::ControllerInputSystem>(controllerSystem->getSignature(world));
    auto colSystem = world.registerSystem<engine::CollisionSystem>();
    world.setSystemSignature<engine::CollisionSystem>(colSystem->getSignature(world));
    auto bombSystem = world.registerSystem<engine::BombSystem>();
    world.setSystemSignature<engine::BombSystem>(bombSystem->getSignature(world));
    auto playerBombSystem = world.registerSystem<engine::PlayerBombSystem>();
    world.setSystemSignature<engine::PlayerBombSystem>(playerBombSystem->getSignature(world));
    auto particleSystem = world.registerSystem<engine::ExplosionParticleSystem>();
    world.setSystemSignature<engine::ExplosionParticleSystem>(particleSystem->getSignature(world));

    auto map = world.createEntity();
    world.addComponent(map, cubemapSystem->createCubemap("./resources/map1"));
    world.addComponent(map, engine::Transform({{0}, {0}, 1.0}));

    auto zilla1 = world.createEntity();
    world.addComponent(zilla1, engine::Animations());
    world.addComponent(zilla1, engine::Transform({{1.0, .0, 1.0}, {0}, .4}));
    world.addComponent(zilla1, engine::InputSettings({false, 0, KEY_W, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, false}));
    world.addComponent(zilla1, engine::ControllerInput());
    world.addComponent(zilla1, engine::Collision());
    world.addComponent(zilla1, engine::BombSettings({0, 1, false, 3}));
    world.addComponent(zilla1, engine::PlayerStat({3, "Zilla1"}));
    animSystem->addAnimation(zilla1, world, {"Run", "./resources/ZillaRun", ""}, engine::Animation({30, 0}));
    animSystem->addAnimation(zilla1, world, {"Idle", "./resources/ZillaIdle", ""}, engine::Animation({30, 0}));

    auto kong1 = world.createEntity();
    world.addComponent(kong1, engine::Animations());
    world.addComponent(kong1, engine::Transform({{13.0, .0, 1.0}, {0}, .2}));
    world.addComponent(kong1, engine::InputSettings({false, 0, KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_K, KEY_L, nbPlayers < 2}));
    world.addComponent(kong1, engine::ControllerInput());
    world.addComponent(kong1, engine::Collision());
    world.addComponent(kong1, engine::BombSettings({0, 1, false, 3}));
    world.addComponent(kong1, engine::PlayerStat({3, "Kong1"}));
    animSystem->addAnimation(kong1, world, {"Run", "./resources/KongRun", ""}, engine::Animation({24, 0}));
    animSystem->addAnimation(kong1, world, {"Idle", "./resources/KongIdle", ""}, engine::Animation({24, 0}));
    if (nbPlayers < 2) world.addComponent(kong1, engine::AI({engine::AI::Direction::NONE}));

    auto zilla2 = world.createEntity();
    world.addComponent(zilla2, engine::Animations());
    world.addComponent(zilla2, engine::Transform({{1.0, .0, 13.0}, {0}, .2}));
    world.addComponent(zilla2, engine::InputSettings({true, 0, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, nbPlayers < 3}));
    world.addComponent(zilla2, engine::ControllerInput());
    world.addComponent(zilla2, engine::Collision());
    world.addComponent(zilla2, engine::BombSettings({0, 1, false, 3}));
    world.addComponent(zilla2, engine::PlayerStat({3, "Zilla2"}));
    animSystem->addAnimation(zilla2, world, {"Run", "./resources/KongRun", ""}, engine::Animation({24, 0}));
    animSystem->addAnimation(zilla2, world, {"Idle", "./resources/KongIdle", ""}, engine::Animation({24, 0}));
    if (nbPlayers < 3) world.addComponent(zilla2, engine::AI({engine::AI::Direction::NONE}));

    auto kong2 = world.createEntity();
    world.addComponent(kong2, engine::Animations());
    world.addComponent(kong2, engine::Transform({{13.0, .0, 13.0}, {0}, .4}));
    world.addComponent(kong2, engine::InputSettings({true, 1, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, nbPlayers < 4}));
    world.addComponent(kong2, engine::ControllerInput());
    world.addComponent(kong2, engine::Collision());
    world.addComponent(kong2, engine::BombSettings({0, 1, false, 3}));
    world.addComponent(kong2, engine::PlayerStat({3, "Kong2"}));
    animSystem->addAnimation(kong2, world, {"Run", "./resources/ZillaRun", ""}, engine::Animation({30, 0}));
    animSystem->addAnimation(kong2, world, {"Idle", "./resources/ZillaIdle", ""}, engine::Animation({30, 0}));
    if (nbPlayers < 4) world.addComponent(kong2, engine::AI({engine::AI::Direction::NONE}));

    Shader shaderBlur = LoadShader(0, "resources/shaders/blur.fs");
    Shader shaderGetBrightPixels = LoadShader(0, "resources/shaders/getBrightPixels.fs");
    Shader shaderBlending = LoadShader(0, "resources/shaders/blending.fs");

    RenderTexture2D render_scene = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);
    RenderTexture2D render_brightPixels1 = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);
    RenderTexture2D render_brightPixels2 = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

    // ---------------
    Shader shaderLighting = LoadShader("resources/shaders/base_lighting.vs", "resources/shaders/lighting.fs");
    shaderLighting.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(shaderLighting, "matModel");
    shaderLighting.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shaderLighting, "viewPos");

    Light light = CreateLight(LIGHT_POINT, Vector3({ 0, 12, 0 }), Vector3Zero(), WHITE, shaderLighting);
    light.enabled = false;
    // ---------------

    float angle = -PI * 0.5f;

    lib::Stopwatch sw;
    sw.start();
    for (double dt = 0, elapsed = 0; !WindowShouldClose() && !gm.shouldStop(); dt = sw.getElapsedTime() - elapsed) {
        elapsed = sw.getElapsedTime();
        UpdateCamera(&camera);

        engine::Cubemap &cmap = world.getComponent<engine::Cubemap>(map);

        controllerSystem->update(world);
        bombSystem->update(world, cmap);
        playerBombSystem->update(world, cmap);
        colSystem->update(world, cmap.collision);
        aiSystem->update(world, cmap.collision);
        particleSystem->update(world);
        animSystem->update(world, dt);
        endSystem->update(world, gm);

        // LIGHT
        angle += 0.003f;
        light.position.y = cosf(angle)*10.0f + 7.0f;
        light.position.z = cosf(angle*0.7f)*7.0f + 7.0f;
        light.position.x = sinf(angle)*10.0f + 7.0f;


        light.color.r = 15;
        light.color.g = 20 + (light.position.y * 7);
        light.color.b = 60 + (light.position.y * 8);

        UpdateLightValues(shaderLighting, light);
        float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
        SetShaderValue(shaderLighting, shaderLighting.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
        // --

        BeginDrawing();

            BeginTextureMode(render_scene);
            ClearBackground({light.color.r, light.color.g, light.color.b, 255}); // always after BeginTextureMode()

            if (IsKeyPressed(KEY_L)) { light.enabled = !light.enabled;}

            BeginMode3D(camera);
            cubemapSystem->draw(world, &shaderLighting);
            animSystem->draw(world, &shaderLighting);
            bombSystem->draw(world, &shaderLighting);
            particleSystem->draw(world);

            if (light.enabled) { DrawSphereEx(light.position, 0.2f, 8, 8, WHITE); }

            EndMode3D();

            // get bright pixles into render_brightPixels
            BeginTextureMode(render_brightPixels1);
            ClearBackground({0, 0, 0, 255}); // always after BeginTextureMode()

            BeginShaderMode(shaderGetBrightPixels);
                DrawTextureRec(render_scene.texture, Rectangle({ 0, 0, float(WINDOW_WIDTH), float(-WINDOW_HEIGHT) }), Vector2({ 0, 0 }), WHITE);

            BeginShaderMode(shaderBlur);
            // two-pass gaussian blur
            int horizontal = 0;
            for (int i = 0 ; i < 4 ; ++i) {
                int loc = GetShaderLocation(shaderBlur, "horizontal");

                SetShaderValue(shaderBlur, loc, &horizontal, SHADER_UNIFORM_INT);
                if (horizontal == 0) {
                    BeginTextureMode(render_brightPixels2);
                    DrawTextureRec(render_brightPixels1.texture, Rectangle({ 0, 0, float(WINDOW_WIDTH), float(-WINDOW_HEIGHT) }), Vector2({ 0, 0 }), WHITE);
                } else {
                    BeginTextureMode(render_brightPixels1);
                    DrawTextureRec(render_brightPixels2.texture, Rectangle({ 0, 0, float(WINDOW_WIDTH), float(-WINDOW_HEIGHT) }), Vector2({ 0, 0 }), WHITE);
                }
                horizontal = 1 - horizontal;
            }

            EndTextureMode();

            int texture_loc = GetShaderLocation(shaderBlending, "texture1");
            BeginShaderMode(shaderBlending);
            SetShaderValueTexture(shaderBlending, texture_loc, render_brightPixels1.texture);
            DrawTextureRec(render_scene.texture, Rectangle({ 0, 0, float(render_scene.texture.width), float(-render_scene.texture.height) }), Vector2({ 0, 0 }), WHITE);
            // DrawTextureRec(render_brightPixels1.texture, (Rectangle){ 0, 0, (float)WINDOW_WIDTH, (float)-WINDOW_HEIGHT }, Vector2({ 0, 0 }), WHITE);
            EndShaderMode();

        // DrawFPS(10, 10); // DEBUG
        EndDrawing();
    }

    RemoveLight(light);
    return (gm.returnCode());
}

int main(int argc UNUSED, char const *argv[] UNUSED)
{
    #ifndef DEBUG
        SetTraceLogLevel(LOG_NONE);
    #endif

    ECS::GameManager gm;

    initWindow();

    srand(time(NULL));

    gm.addScene(sceneMenu, "Menu");
    gm.addScene(sceneSetup, "Setup");
    gm.addScene(mainGame, "Start");
    gm.addScene(sceneEnd, "End");
    gm.run();
    return 0;
}
