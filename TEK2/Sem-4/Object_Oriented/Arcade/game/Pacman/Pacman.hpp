/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** pacman.hpp
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "IGameModule.hpp"
#include "GameObject.hpp"

namespace arcade {

    class Pacman : public IGameModule
    {
        public:
            Pacman();
             ~Pacman(void) {};
             const std::string &getName(void) override;
            // See the class documentation for more info
             void init(void) override;
            // See the class documentation for more info
             void stop(void) override;
            // // Update is called at each frame
            std::vector<GameObject> &update(std::vector<Input::Key> input) override;
            // // Returns true if game is over
            // // This will trigger a call to the stop method if true
             bool is_over(void) override;
            // // This will be called just before the stop method to collect the data and store it.
             int get_score(void) override;
        private:
            std::vector<arcade::GameObject> object;
            std::vector<std::string> map;
            int score;
            std::string name;
            int direction;
            int posX;
            int posY;
            int GposX;
            int GposY;
            int posFY;
            int posFX;
            bool over;
            std::vector<std::string> go_up(void);
            std::vector<std::string> go_down(void);
            std::vector<std::string> go_left(void);
            std::vector<std::string> go_right(void);
            std::vector<std::string> iago_up(void);
            std::vector<std::string> iago_left(void);
            std::vector<std::string> iago_down(void);
            std::vector<std::string> iago_right(void);
            std::vector<std::string> ia_move(void);

    };
    extern "C" {
        IGameModule *entryPoint(void);
    }
}

#endif