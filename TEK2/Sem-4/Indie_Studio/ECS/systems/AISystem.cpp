/*
** EPITECH PROJECT, 2020
** tmp
** File description:
** AISytem.cpp
*/


#include "ECS/systems/AISystem.hpp"

namespace engine {
    static void createBomb(ECS::World &world, ECS::Guid entity, Transform &tr)
    {
        BombSettings &settings = world.getComponent<BombSettings>(entity);
        if (settings.nbBombs > 0) {
            auto bomb = world.createEntity();
            world.addComponent(bomb, Bomb({settings.lifetimeBuff + 100, settings.power, settings.piercing, entity}));
            world.addComponent(bomb, Transform({
                Vector3{float(int(tr.position.x + 0.5)), tr.position.y, float(int(tr.position.z + 0.5))},
                {0}, 1
            }));
            settings.nbBombs--;
        }
    }

    static bool isWalkable(AISystem::CollideMap &map, int z, int x)
    {
        if (map[z][x] != Cubemap::INDESTRUCTIBLE &&
            map[z][x] != Cubemap::DESTRUCTIBLE &&
            map[z][x] != Cubemap::BOMB)
        {
            return true;
        }
        return false;
    }

    static void move(ControllerInput &inp, AI::Direction dir)
    {
        switch (dir) {
            case AI::Direction::UP:
                inp.up = true;
                break;
            case AI::Direction::DOWN:
                inp.down = true;
                break;
            case AI::Direction::LEFT:
                inp.left = true;
                break;
            case AI::Direction::RIGHT:
                inp.right = true;
                break;
            default:
                break;
        }
    }

    static void centerToBlock(Transform &tr, ControllerInput &inp)
    {
        float posX = tr.position.x + 0.5f;
        float posZ = tr.position.z + 0.5f;

        float distX = fmod(posX, 1.0f);
        float distZ = fmod(posZ, 1.0f);

        if (inp.up || inp.down) {
            if (distX < 0.5f)
                move(inp, AI::Direction::RIGHT);
            else
                move(inp, AI::Direction::LEFT);
        }
        else if (inp.left || inp.right) {
            if (distZ < 0.5f)
                move(inp, AI::Direction::DOWN);
            else
                move(inp, AI::Direction::UP);
        }
    }

    static bool shouldChangeDirection(Transform &tr, AISystem::CollideMap &map, AI &ai)
    {
        int posX = tr.position.x + 0.5f;
        int posZ = tr.position.z + 0.5f;

        if (ai.dir == AI::NONE)
            return (true);
        if (ai.dir == AI::UP) {
            if (isWalkable(map, posZ - 1, posX) == 0)
                return (true);
        }
        else if (ai.dir == AI::DOWN) {
            if (isWalkable(map, posZ + 1, posX) == 0)
                return (true);
        }
        else if (ai.dir == AI::LEFT) {
            if (isWalkable(map, posZ, posX - 1) == 0)
                return (true);
        }
        else if (ai.dir == AI::RIGHT) {
            if (isWalkable(map, posZ, posX + 1) == 0)
                return (true);
        }

        std::vector<engine::AI::Direction> possibleDir;

        if (ai.dir == AI::UP || ai.dir == AI::DOWN) {
            if (isWalkable(map, posZ, posX - 1) == false)
                possibleDir.push_back(engine::AI::Direction::LEFT);
            if (isWalkable(map, posZ, posX + 1) == false)
                possibleDir.push_back(engine::AI::Direction::RIGHT);
        } else if (ai.dir == AI::LEFT || ai.dir == AI::RIGHT) {
            if (isWalkable(map, posZ - 1, posX) == false)
                possibleDir.push_back(engine::AI::Direction::UP);
            if (isWalkable(map, posZ + 1, posX) == false)
                possibleDir.push_back(engine::AI::Direction::DOWN);
        }
        if (possibleDir.size() > 0) {
            if (rand() % 10 == 0)
                return (true);
        }
        return (false);
    }
}

engine::AISystem::AISystem(void)
{
}

ECS::Signature engine::AISystem::getSignature(ECS::World &world)
{
    ECS::Signature signature;
    signature.set(world.getComponentType<AI>());
    signature.set(world.getComponentType<engine::Transform>());
    signature.set(world.getComponentType<ControllerInput>());
    return signature;
}

void engine::AISystem::update(ECS::World &world, engine::AISystem::CollideMap &map)
{
    for (auto &&entity : _entities) {
        auto &tr = world.getComponent<engine::Transform>(entity);
        auto &inp = world.getComponent<ControllerInput>(entity);
        auto &ai = world.getComponent<AI>(entity);

        AI::Direction tmp = this->checkBomb(tr, map);

        inp.left = false;
        inp.right = false;
        inp.up = false;
        inp.down = false;

        if (shouldChangeDirection(tr, map, ai)) {
            if (tmp == AI::NONE)
                this->playAggressive(world, entity, tr, map, inp, ai);
            else
                this->playSafe(tmp, tr, map, inp, ai);
            centerToBlock(tr, inp);
        }
        move(inp, ai.dir);
    }
}

engine::AI::Direction engine::AISystem::checkBomb(engine::Transform &tr, engine::AISystem::CollideMap &map)
{
    const int viewDistance = 5;
    int posX = tr.position.x + 0.5f;
    int posZ = tr.position.z + 0.5f;

    AI::Direction dir = AI::NONE;
    int bombDistance = 100;

    if (map[posZ][posX] == Cubemap::BOMB)
        return AI::SELF;

    for (int i = 1; i < viewDistance; i++) {
        if (posZ + i < 14 && map[posZ + i][posX] == Cubemap::BOMB) {
            if (i < bombDistance) {
                bombDistance = i;
                dir = AI::DOWN;
            }
        }
    }
    for (int i = 1; i < viewDistance; i++) {
        if (posZ - i > 0 && map[posZ - i][posX] == Cubemap::BOMB) {
            if (i < bombDistance) {
                bombDistance = i;
                dir = AI::UP;
            }
        }
    }
    for (int i = 1; i < viewDistance; i++) {
        if (posX + i < 14 && map[posZ][posX + i] == Cubemap::BOMB) {
            if (i < bombDistance) {
                bombDistance = i;
                dir = AI::RIGHT;
            }
        }
    }
    for (int i = 1; i < viewDistance; i++) {
        if (posX - i > 0 && map[posZ][posX - i] == Cubemap::BOMB) {
            if (i < bombDistance) {
                bombDistance = i;
                dir = AI::LEFT;
            }
        }
    }
    return dir;
}

void engine::AISystem::playSafe(AI::Direction dir, engine::Transform &tr, engine::AISystem::CollideMap &map, ControllerInput &inp, AI &ai)
{
    const int posX = tr.position.x + 0.5f;
    const int posZ = tr.position.z + 0.5f;

    if (dir == AI::SELF) {
        if (isWalkable(map, posZ, posX + 1))
            ai.dir = AI::Direction::RIGHT;
        else if (isWalkable(map, posZ, posX - 1))
            ai.dir = AI::Direction::LEFT;
        else if (isWalkable(map, posZ + 1, posX))
            ai.dir = AI::Direction::DOWN;
        else if (isWalkable(map, posZ - 1, posX))
            ai.dir = AI::Direction::UP;
    }

    if (dir == AI::UP) {
        if (isWalkable(map, posZ, posX + 1))
            ai.dir = AI::Direction::RIGHT;
        else if (isWalkable(map, posZ, posX - 1))
            ai.dir = AI::Direction::LEFT;
        else if (isWalkable(map, posZ + 1, posX))
            ai.dir = AI::Direction::DOWN;
    }
    else if (dir == AI::DOWN) {
        if (isWalkable(map, posZ, posX + 1))
            ai.dir = AI::Direction::RIGHT;
        else if (isWalkable(map, posZ, posX - 1))
            ai.dir = AI::Direction::LEFT;
        else if (isWalkable(map, posZ - 1, posX))
            ai.dir = AI::Direction::UP;
    }
    else if (dir == AI::LEFT) {
        if (isWalkable(map, posZ, posX + 1))
            ai.dir = AI::Direction::RIGHT;
        else if (isWalkable(map, posZ - 1, posX))
            ai.dir = AI::Direction::UP;
        else if (isWalkable(map, posZ + 1, posX))
            ai.dir = AI::Direction::DOWN;
    }
    else if (dir == AI::RIGHT) {
        if (isWalkable(map, posZ, posX - 1))
            ai.dir = AI::Direction::LEFT;
        else if (isWalkable(map, posZ - 1, posX))
            ai.dir = AI::Direction::UP;
        else if (isWalkable(map, posZ + 1, posX))
            ai.dir = AI::Direction::DOWN;
    }
}

void engine::AISystem::playAggressive(ECS::World &world, ECS::Guid entity, engine::Transform &tr, engine::AISystem::CollideMap &map, ControllerInput &inp, AI &ai)
{
    const int posX = tr.position.x + 0.5f;
    const int posZ = tr.position.z + 0.5f;

    if (map[posZ][posX + 1] == Cubemap::DESTRUCTIBLE ||
        map[posZ][posX - 1] == Cubemap::DESTRUCTIBLE ||
        map[posZ + 1][posX] == Cubemap::DESTRUCTIBLE ||
        map[posZ - 1][posX] == Cubemap::DESTRUCTIBLE)
    {
        createBomb(world, entity, tr);
    } else { // if no wall to destroy, move in random direction
        std::vector<engine::AI::Direction> possibleDir;

        if (isWalkable(map, posZ + 1, posX))
            possibleDir.push_back(engine::AI::Direction::DOWN);
        if (isWalkable(map, posZ - 1, posX))
            possibleDir.push_back(engine::AI::Direction::UP);
        if (isWalkable(map, posZ, posX + 1))
            possibleDir.push_back(engine::AI::Direction::RIGHT);
        if (isWalkable(map, posZ, posX - 1))
            possibleDir.push_back(engine::AI::Direction::LEFT);

        if (possibleDir.size() > 0) {
            int rd = rand() % possibleDir.size();
            ai.dir = possibleDir[rd];
        }
    }
}