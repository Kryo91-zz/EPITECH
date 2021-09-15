/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** AnimatorSystem.cpp
*/

#include "ECS/systems/AnimatorSystem.hpp"

namespace engine
{
    void AnimatorSystem::addAnimation(ECS::Guid entity, ECS::World &world, AnimationSrc src, Animation anim)
    {
        if (!src.texturePath.empty())
            anim.texture = LoadTexture( src.texturePath.c_str() );
        std::vector<std::string> entries;

        try {
            for (const auto &entry : std::filesystem::directory_iterator(src.folderPath)) {
                std::regex reg(".+\\.obj$");
                std::string path = entry.path().string();
                if ( !(std::regex_match(path, reg)) ) {
                    continue;
                }
                entries.push_back(entry.path().string());
            }
            std::sort(entries.begin(), entries.end());
            for (const auto &entry : entries) {
                anim.nbFrames += 1;
                Model model = LoadModel( entry.c_str() );
                if (!src.texturePath.empty())
                    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = anim.texture;
                anim.models.push_back(model);
            }
            auto &c = world.getComponent<Animations>(entity);
            c.animations.insert(std::make_pair(src.animationName, anim));
            if (c.currentAnimation.empty())
                c.currentAnimation = src.animationName;
        } catch (std::exception &e) {
            throw std::runtime_error(e.what());
        }
    }

    void AnimatorSystem::setCurrentAnimation(ECS::Guid entity, ECS::World &world, std::string name)
    {
        world.getComponent<Animations>(entity).currentAnimation = name;
    }

    void AnimatorSystem::update(ECS::World &world, ECS::timestep dt)
    {
        for (auto &&entity : _entities) {
            auto &c = world.getComponent<Animations>(entity);
            Animation &anim = c.animations[c.currentAnimation];

            anim.elapsedTime += dt;
            if (anim.elapsedTime > (1.0f/anim.frameRate)) {
                anim.currentFrame += 1;
                if (anim.currentFrame >= anim.nbFrames)
                    anim.currentFrame = 0;
                anim.elapsedTime = 0;
            }
        }
    }

    void AnimatorSystem::draw(ECS::World &world, Shader *shader)
    {
        for (auto &&entity : _entities) {
            auto &c = world.getComponent<Animations>(entity);

            Animation &anim = c.animations[c.currentAnimation];
            engine::Transform &tr = world.getComponent<engine::Transform>(entity);
            ControllerInput &inp = world.getComponent<ControllerInput>(entity);
            if (inp.up) tr.rotation.y = DEG2RAD * 180;
            if (inp.left) tr.rotation.y = DEG2RAD * 90;
            if (inp.down) tr.rotation.y = DEG2RAD * 0;
            if (inp.right) tr.rotation.y = DEG2RAD * -90;

            std::string animName = inp.up || inp.left || inp.down || inp.right ? "Run" : "Idle";
            if (animName != c.currentAnimation)
                this->setCurrentAnimation(entity, world, animName);

            if (shader) {
               anim.models[anim.currentFrame].materials[0].shader = *shader;
            }

            anim.models[anim.currentFrame].transform = MatrixRotateXYZ(tr.rotation);
            DrawModel(anim.models[anim.currentFrame], tr.position, tr.scale, WHITE);
        }
    }

    ECS::Signature AnimatorSystem::getSignature(ECS::World &world)
    {
        ECS::Signature signature;
        signature.set(world.getComponentType<Animations>());
        signature.set(world.getComponentType<engine::Transform>());
        signature.set(world.getComponentType<ControllerInput>());
        return signature;
    }

}
