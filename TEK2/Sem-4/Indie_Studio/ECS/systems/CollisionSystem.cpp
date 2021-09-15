/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** CubemapSystem.cpp
*/

#include "ECS/systems/CollisionSystem.hpp"

namespace engine
{

    static bool pickUp(BombSettings &s, std::array<std::array<int, 16>, 16> &map, const int newZ, const int newX)
    {
        switch (map[newZ][newX])
        {
            case Cubemap::POWER_PLUS:   s.power += 1; map[newZ][newX] = Cubemap::FLOOR; return true;
            case Cubemap::PIERCING:     s.piercing = true; map[newZ][newX] = Cubemap::FLOOR; return true;
            case Cubemap::MINUS_LIFE:   s.lifetimeBuff -= 20; map[newZ][newX] = Cubemap::FLOOR; return true;
            case Cubemap::PLUS_LIFE:    s.lifetimeBuff += 20; map[newZ][newX] = Cubemap::FLOOR; return true;
            case Cubemap::BOMBS_PLUS:    s.nbBombs += 1; map[newZ][newX] = Cubemap::FLOOR; return true;
            default:                    return false;
        }
    }

    void CollisionSystem::update(ECS::World &world, std::array<std::array<int, 16>, 16> &map)
    {
        const float speed = 0.1f;
        for (auto &&entity : _entities) {

            ControllerInput &input = world.getComponent<ControllerInput>(entity);
            engine::Transform &tr = world.getComponent<engine::Transform>(entity);
            engine::BombSettings &settings = world.getComponent<BombSettings>(entity);

            const float size = 0.2f;
            const float x = tr.position.x + 0.5f;
            const float z = tr.position.z + 0.5f;

            int newX;
            int newZ;

            if (input.up) {
                newZ = z - speed - size;
                newX = x;

                bool insideBomb = map[int(z)][int(x)] == Cubemap::BOMB && map[newZ][newX] == Cubemap::BOMB;
                if (insideBomb || map[newZ][newX] == Cubemap::FLOOR || pickUp(settings, map, newZ, newX))
                    tr.position.z -= speed;
            }

            if (input.down) {
                newZ = z + speed + size;
                newX = x;

                bool insideBomb = map[int(z)][int(x)] == Cubemap::BOMB && map[newZ][newX] == Cubemap::BOMB;
                if (insideBomb || map[newZ][newX] == Cubemap::FLOOR || pickUp(settings, map, newZ, newX))
                    tr.position.z += speed;
            }

            newZ = z;
            if (input.left) {
                newX = x - speed - size;

                bool insideBomb = map[int(z)][int(x)] == Cubemap::BOMB && map[newZ][newX] == Cubemap::BOMB;
                if (insideBomb || map[newZ][newX] == Cubemap::FLOOR || pickUp(settings, map, newZ, newX))
                    tr.position.x -= speed;
            }

            if (input.right) {
                newZ = z;
                newX = x + speed + size;

                bool insideBomb = map[int(z)][int(x)] == Cubemap::BOMB && map[newZ][newX] == Cubemap::BOMB;
                if (insideBomb || map[newZ][newX] == Cubemap::FLOOR || pickUp(settings, map, newZ, newX))
                    tr.position.x += speed;
            }
        }
    }

    ECS::Signature CollisionSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<ControllerInput>());
        signature.set(world.getComponentType<engine::Transform>());
        signature.set(world.getComponentType<Collision>());
        signature.set(world.getComponentType<BombSettings>());
        return signature;
    }
} // namespace engine
