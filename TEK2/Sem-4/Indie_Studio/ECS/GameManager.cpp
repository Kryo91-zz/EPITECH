/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** GameManager.cpp
*/

#include "ECS/GameManager.hpp"

namespace ECS
{

    bool compareEntries(
        std::pair<std::string, GameManager::Scene> &left,
        std::pair<std::string, GameManager::Scene> &right)
    {
        return left.first == right.first;
    }

    GameManager::GameManager(void) {this->_world.init();}

    void GameManager::addScene(Scene scene, std::string name)
    {
        _scenes.push_back({name, scene});
    }

    void GameManager::removeScene(std::string name)
    {
        auto &&it = std::find_if(_scenes.begin(), _scenes.end(),
            [name](std::pair<std::string, Scene> p)
            {return p.first == name;}
        );

        if (it != _scenes.end())
            _scenes.erase(it);
    }

    int GameManager::getSceneIndex(std::string name)
    {
        auto it = std::find_if(_scenes.begin(), _scenes.end(),
            [name](std::pair<std::string, Scene> p)
            {return p.first == name;}
        );

        if (it == _scenes.end())
            throw lib::Exception("Can't find scene named : " + name);
        return std::distance(_scenes.begin(), it);
    }

    std::string GameManager::getSceneName(size_t idx)
    {
        if (idx >= _scenes.size())
            throw lib::Exception("Scene with idx " + std::to_string(idx) + " doesn't exist");
        return (_scenes[idx].first);
    }

    void GameManager::gameLoop(std::vector<std::pair<std::string, Scene>>::iterator &pair)
    {
        for (int ret = pair->second(_world, *this);
            ret != QUIT;
            ret = pair->second(_world, *this))
        {
            if (ret == PREV) {
                if (_activeSceneIndex <= 0)
                    throw lib::Exception("No previous scene.");
                pair--;
                _activeSceneIndex -= 1;
                _activeSceneName = pair->first;
            } else if (ret == NEXT) {
                if (_activeSceneIndex + 1 >= _scenes.size())
                    throw lib::Exception("No next scene.");
                pair++;
                _activeSceneIndex += 1;
                _activeSceneName = pair->first;
            } else {
                _activeSceneName = this->getSceneName(ret);
                _activeSceneIndex = ret;
                pair = std::next(_scenes.begin(), ret);
            }
            _returnCode = QUIT;
            _stop = false;
            _world.reset();
        }
    }

    void GameManager::run(void)
    {
        _world.reset();
        auto pair = (_scenes.begin());
        _activeSceneIndex = 0;
        _activeSceneName = pair->first;

        this->gameLoop(pair);

    }

    void GameManager::run(int sceneIdx)
    {
        _world.reset();
        _activeSceneName = this->getSceneName(sceneIdx);
        auto pair = std::find_if(_scenes.begin(), _scenes.end(),
            [this](std::pair<std::string, Scene> p)
            {return p.first == this->getActiveSceneName();}
        );
        _activeSceneIndex = pair - _scenes.begin();

        this->gameLoop(pair);
    }

    void GameManager::run(std::string sceneName)
    {
        _world.reset();
        auto pair = std::find_if(_scenes.begin(), _scenes.end(),
            [this](std::pair<std::string, Scene> p)
            {return p.first == this->getActiveSceneName();}
        );
        if (pair == _scenes.end())
            throw ("Cannot find scene named " + sceneName);
        _activeSceneIndex = pair - _scenes.begin();
        _activeSceneName = pair->first;

        this->gameLoop(pair);
    }
} // namespace ECS
