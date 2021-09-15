/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** CubemapSystem.cpp
*/

#include "ECS/systems/CubemapSystem.hpp"

namespace engine
{
    Cubemap CubemapSystem::createCubemap(std::string mapFolder)
    {
        engine::Cubemap cubemap = {0};

        std::string mapSource = mapFolder+"/cubicmap.png";
        std::string mapTexture = mapFolder+"/cubicmap_atlas.png";
        std::string mapCollision = mapFolder+"/physicmap.txt";
        std::string blockSrc = mapFolder+"/block.png";

        cubemap.blockModel = LoadModel("Default cube");
        cubemap.blockModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(blockSrc.c_str());
        Mesh mesh = GenMeshCubicmap(LoadImage(mapSource.c_str()), Vector3({ 1.0f, 1.0f, 1.0f }));
        cubemap.model = LoadModelFromMesh(mesh);

        cubemap.texture = LoadTexture(mapTexture.c_str());
        cubemap.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = cubemap.texture;

        _modelPower = LoadModel("Default cube");
        _modelPower.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/itemPower.png");

        _modelPiercing = LoadModel("Default cube");
        _modelPiercing.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/itemPiercing.png");

        _modelLifePlus = LoadModel("Default cube");
        _modelLifePlus.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/itemLifePlus.png");

        _modelLifeMinus = LoadModel("Default cube");
        _modelLifeMinus.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/itemLifeMinus.png");

        _modelBombPlus = LoadModel("Default cube");
        _modelBombPlus.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/itemBombPlus.png");

        std::ifstream t(mapCollision.c_str());
        std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
        int i = 0;
        for (int y = 0; y < 15; y++) {
            for (int x = 0; x < 15; x++) {
                if (str.c_str()[i] == 10)
                    i++;
                cubemap.collision[y][x] = str.c_str()[i] - 48;
                i++;
            }
        }

        return (cubemap);
    }

    void CubemapSystem::draw(ECS::World &world, Shader *shader)
    {
        for (auto &&entity : _entities) {
            Cubemap &cubemap = world.getComponent<Cubemap>(entity);
            engine::Transform &transform = world.getComponent<Transform>(entity);

            if (shader) {
                cubemap.model.materials[0].shader = *shader;
                cubemap.blockModel.materials[0].shader = *shader;
                _modelPower.materials[0].shader = *shader;
                _modelLifePlus.materials[0].shader = *shader;
                _modelLifeMinus.materials[0].shader = *shader;
                _modelPiercing.materials[0].shader = *shader;
                _modelBombPlus.materials[0].shader = *shader;
            }

            for (float y = 0; y < cubemap.collision.size(); y += 1.0) {
                for (float x = 0; x < cubemap.collision.size(); x += 1.0) {
                    switch (cubemap.collision[y][x]) {
                        case Cubemap::DANGER:       cubemap.collision[y][x] = Cubemap::FLOOR; break;
                        case Cubemap::DESTRUCTIBLE: DrawModel(cubemap.blockModel, {x, 0.5f, y}, .75f, WHITE); break;
                        case Cubemap::POWER_PLUS:   DrawModel(_modelPower, {x, 0.5f, y}, .75f, WHITE); break;
                        case Cubemap::PLUS_LIFE:    DrawModel(_modelLifePlus, {x, 0.5f, y}, .75f, WHITE); break;
                        case Cubemap::MINUS_LIFE:   DrawModel(_modelLifeMinus, {x, 0.5f, y}, .75f, WHITE); break;
                        case Cubemap::PIERCING:     DrawModel(_modelPiercing, {x, 0.5f, y}, .75f, WHITE); break;
                        case Cubemap::BOMBS_PLUS:   DrawModel(_modelBombPlus, {x, 0.5f, y}, .75f, WHITE); break;
                        default:                    break;
                    }
                }
            }
            DrawModel(cubemap.model, transform.position, transform.scale, WHITE);
        }
    }

    ECS::Signature CubemapSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<Cubemap>());
        signature.set(world.getComponentType<engine::Transform>());
        return signature;
    }
} // namespace engine
