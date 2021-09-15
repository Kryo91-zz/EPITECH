/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** GameManager.hpp
*/

#pragma once

#include "ECS/World.hpp"

namespace ECS
{
    class GameManager
    {
        public:
            using Scene = std::function<int (World &, GameManager &)>;
            enum ReturnCodes {
                QUIT = -1,
                NEXT = -2,
                PREV = -3
            };
            GameManager(void);
            ~GameManager(void) = default;
            /**
             * @brief Adds scene with the associated name so that it can be loaded.
             * @param name The scene name
             */
            void addScene(Scene scene, std::string name);
            /**
             * @brief Removes scene with the associated name.
             * If the scene doesn't exist, this is a no-op.
             * @param name The scene name
             */
            void removeScene(std::string name);
            int getActiveSceneIndex(void) {return _activeSceneIndex;};
            std::string getActiveSceneName(void) {return _activeSceneName;};
            int getSceneIndex(std::string name);
            std::string getSceneName(size_t idx);

            bool shouldStop(void) { return _stop; };
            void stop(bool p = true) { _stop = p; };
            int returnCode(void) { return _returnCode; };
            void setReturnCode(int code) { _returnCode = code; };

            void run(void);
            void run(int sceneIdx);
            void run(std::string sceneName);

            template <typename T>
            T &getSharedState(void) {
                static T state;
                return state;
            };
        private:
            void gameLoop(std::vector<std::pair<std::string, Scene>>::iterator &pair);
            World _world;
            std::vector<std::pair<std::string, Scene>> _scenes;
            // std::map<std::string, Scene> _scenes;
            std::string _activeSceneName;
            size_t _activeSceneIndex;
            bool _stop = false;
            int _returnCode = QUIT;
    };
} // namespace ECS
