/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** IGameModule.hpp
*/


#pragma once

#include "GameObject.hpp"

namespace arcade
{
    // A game module should store a game's logic.
    // It needs to take input and return a list of game objects to be displayed
    // on each update
    // init is important because it allows the
    // constructor to load the game without launching it.
    // stop should reset the game to prepare it for a restart.
    // These function will be called whenever a game should be launched or destroyed.
    class IGameModule
    {
        public:
            virtual ~IGameModule(void) = default;
            virtual const std::string &getName(void) = 0;
            // See the class documentation for more info
            virtual void init(void) = 0;
            // See the class documentation for more info
            virtual void stop(void) = 0;
            // // Update is called at each frame
            virtual const std::vector<GameObject> &update(std::vector<Input::Key> input) = 0;
            // // Returns true if game is over
            // // This will trigger a call to the stop method if true
            virtual bool is_over(void) = 0;
            // // This will be called just before the stop method to collect the data and store it.
             virtual int get_score(void) = 0;
    };
}