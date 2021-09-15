/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** PlayerBombSystem.cpp
*/

#include "ECS/systems/PlayerBombSystem.hpp"

namespace engine
{
    ECS::Signature PlayerBombSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<engine::Transform>());
        signature.set(world.getComponentType<ControllerInput>());
        signature.set(world.getComponentType<BombSettings>());
        signature.set(world.getComponentType<PlayerStat>());
        return signature;
    }

    void PlayerBombSystem::update(ECS::World &world, Cubemap &map)
    {
        std::vector<ECS::Guid> toRemove;

        for (auto &&player : _entities) {
            auto &input = world.getComponent<ControllerInput>(player);
            auto &settings = world.getComponent<BombSettings>(player);
            auto &tr = world.getComponent<engine::Transform>(player);
            auto &st = world.getComponent<PlayerStat>(player);
            if (map.collision[int(tr.position.z + 0.5)][int(tr.position.x + 0.5)] == Cubemap::DANGER) {
                st.hp -= 1;
                std::cout << st.name << " took a HIT!" << std::endl;
                if (st.hp <= 0) {
                    toRemove.push_back(player);
                    std::cout << st.name << " DIED!" << std::endl;
                }
            }
            if (input.button1 && settings.nbBombs > 0) {
                auto bomb = world.createEntity();
                world.addComponent(bomb, Bomb({settings.lifetimeBuff + 100, settings.power, settings.piercing, player}));
                world.addComponent(bomb, engine::Transform({
                    Vector3{float(int(tr.position.x + 0.5)), tr.position.y, float(int(tr.position.z + 0.5))},
                    {0}, 1
                }));
                settings.nbBombs--;
            }
        }
        for (auto &&player : toRemove)
            world.destroyEntity(player);
    }
} // namespace engine
