/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** BombSystem.cpp
*/

#include "ECS/systems/BombSystem.hpp"

namespace engine
{
    BombSystem::BombSystem(void)
    {
        _model = LoadModel("resources/bomb/bomb.obj");
        _piercingModel = LoadModel("resources/bomb/piercing-bomb.obj");
    }

    ECS::Signature BombSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<engine::Transform>());
        signature.set(world.getComponentType<Bomb>());
        return signature;
    }

    void BombSystem::update(ECS::World &world, Cubemap &map)
    {
        std::vector<ECS::Guid> toRemove;

        for (auto &&entity : _entities) {
            auto &bomb = world.getComponent<Bomb>(entity);
            auto &tr = world.getComponent<Transform>(entity);
            const int z = int(tr.position.z + 0.5f);
            const int x = int(tr.position.x + 0.5f);
            auto &collideMap = map.collision;
            bomb.lifetime--;
            if (bomb.lifetime <= 0) {
                try {
                    world.getComponent<BombSettings>(bomb.parent).nbBombs++;
                } catch(lib::Exception &e) {}
                toRemove.push_back(entity);
                bool zp = false;
                bool zm = false;
                bool xp = false;
                bool xm = false;
                collideMap[z][x] = Cubemap::FLOOR;

                for (int i = 0; i < bomb.power + 1; i++) {
                    if (z + i < 15) {
                        int &cell = collideMap[z + i][x];
                        if (cell == Cubemap::INDESTRUCTIBLE) zp = true;
                        if (cell != Cubemap::INDESTRUCTIBLE && cell != Cubemap::DESTRUCTIBLE && !zp) cell = Cubemap::DANGER;
                        if (cell == Cubemap::DESTRUCTIBLE && !zp) {
                            cell = Cubemap::DANGER;
                            if (!bomb.piercing) zp = true;

                            int t = rand() % 8 == 0 ? Cubemap::POWER_PLUS : -1;
                            t = rand() % 16 == 0 ? Cubemap::PLUS_LIFE : t;
                            t = rand() % 16 == 0 ? Cubemap::MINUS_LIFE : t;
                            t = rand() % 18 == 0 ? Cubemap::BOMBS_PLUS : t;
                            t = rand() % 20 == 0 ? Cubemap::PIERCING : t;

                            if (t != -1) {
                                cell = t;
                            }
                        }
                    }
                    for (float j = 0; i < bomb.power && j < 5; j++) {
                        if (zp) break;
                        auto particle = world.createEntity();
                        world.addComponent(particle, ExplosionParticle({bomb.piercing ? Color({25, 180, 255}) : Color({255, 180, 25}), 255}));
                        world.addComponent(particle, engine::Transform({{tr.position.x, -.5f, tr.position.z + i + (j / 5.0f)}, {0}, 1}));
                    }

                    if (z - i > -1) {
                        int &cell = collideMap[z - i][x];
                        if (cell == Cubemap::INDESTRUCTIBLE) zm = true;
                        if (cell != Cubemap::INDESTRUCTIBLE && cell != Cubemap::DESTRUCTIBLE && !zm) cell = Cubemap::DANGER;
                        if (cell == Cubemap::DESTRUCTIBLE && !zm) {
                            cell = Cubemap::DANGER;
                            if (!bomb.piercing) zm = true;

                            int t = rand() % 8 == 0 ? Cubemap::POWER_PLUS : -1;
                            t = rand() % 16 == 0 ? Cubemap::PLUS_LIFE : t;
                            t = rand() % 16 == 0 ? Cubemap::MINUS_LIFE : t;
                            t = rand() % 18 == 0 ? Cubemap::BOMBS_PLUS : t;
                            t = rand() % 20 == 0 ? Cubemap::PIERCING : t;

                            if (t != -1) {
                                cell = t;
                            }
                        }
                    }
                    for (float j = 0; i < bomb.power && j < 5; j++) {
                        if (zm) break;
                        auto particle = world.createEntity();
                        world.addComponent(particle, ExplosionParticle({bomb.piercing ? Color({25, 180, 255}) : Color({255, 180, 25}), 255}));
                        world.addComponent(particle, engine::Transform({{tr.position.x, -.5f, tr.position.z - (i+1) + (j / 5.0f)}, {0}, 1}));
                    }

                    if (x + i < 15) {
                        int &cell = collideMap[z][x + i];
                        if (cell == Cubemap::INDESTRUCTIBLE) xp = true;
                        if (cell != Cubemap::INDESTRUCTIBLE && cell != Cubemap::DESTRUCTIBLE && !xp) cell = Cubemap::DANGER;
                        if (cell == Cubemap::DESTRUCTIBLE && !xp) {
                            cell = Cubemap::DANGER;
                            if (!bomb.piercing) xp = true;

                            int t = rand() % 8 == 0 ? Cubemap::POWER_PLUS : -1;
                            t = rand() % 16 == 0 ? Cubemap::PLUS_LIFE : t;
                            t = rand() % 16 == 0 ? Cubemap::MINUS_LIFE : t;
                            t = rand() % 18 == 0 ? Cubemap::BOMBS_PLUS : t;
                            t = rand() % 20 == 0 ? Cubemap::PIERCING : t;

                            if (t != -1) {
                                cell = t;
                            }
                        }
                    }
                    for (float j = 0; i < bomb.power && j < 5; j++) {
                        if (xp) break;
                        auto particle = world.createEntity();
                        world.addComponent(particle, ExplosionParticle({bomb.piercing ? Color({25, 180, 255}) : Color({255, 180, 25}), 255}));
                        world.addComponent(particle, engine::Transform({{tr.position.x + i + (j / 5.0f), -.5f, tr.position.z}, {0}, 1}));
                    }

                    if (x - i > -1) {
                        int &cell = collideMap[z][x - i];
                        if (cell == Cubemap::INDESTRUCTIBLE) xm = true;
                        if (cell != Cubemap::INDESTRUCTIBLE && cell != Cubemap::DESTRUCTIBLE && !xm) cell = Cubemap::DANGER;
                        if (cell == Cubemap::DESTRUCTIBLE && !xm) {
                            cell = Cubemap::DANGER;
                            if (!bomb.piercing) xm = true;

                            int t = rand() % 8 == 0 ? Cubemap::POWER_PLUS : -1;
                            t = rand() % 16 == 0 ? Cubemap::PLUS_LIFE : t;
                            t = rand() % 16 == 0 ? Cubemap::MINUS_LIFE : t;
                            t = rand() % 18 == 0 ? Cubemap::BOMBS_PLUS : t;
                            t = rand() % 20 == 0 ? Cubemap::PIERCING : t;

                            if (t != -1) {
                                cell = t;
                            }
                        }
                    }
                    for (float j = 0; i < bomb.power && j < 5; j++) {
                        if (xm) break;
                        auto particle = world.createEntity();
                        world.addComponent(particle, ExplosionParticle({bomb.piercing ? Color({25, 180, 255}) : Color({255, 180, 25}), 255}));
                        world.addComponent(particle, engine::Transform({{tr.position.x - (i+1) + (j / 5.0f), -.5f, tr.position.z}, {0}, 1}));
                    }
                }
            } else {
                collideMap[z][x] = Cubemap::BOMB;
            }
        }
        for (auto &&entity : toRemove) {
            world.destroyEntity(entity);
        }
    }

    void BombSystem::draw(ECS::World &world, Shader *shader)
    {
        if (shader) {
            _model.materials[0].shader = *shader;
            _piercingModel.materials[0].shader = *shader;
        }

        for (auto &&entity : _entities) {
            auto &tr = world.getComponent<engine::Transform>(entity);
            auto &bomb = world.getComponent<Bomb>(entity);

            if (!bomb.piercing)
                DrawModel(_model, tr.position, 0.4f + sin(bomb.lifetime / 5) / 20, WHITE);
            else
                DrawModel(_piercingModel, tr.position, 0.4f + sin(bomb.lifetime / 5) / 20, WHITE);
        }
    }
} // namespace engine
