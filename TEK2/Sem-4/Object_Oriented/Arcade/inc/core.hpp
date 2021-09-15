/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** core
*/

#pragma once

#include "Include.hpp"
#include "IGraphicalLibrary.hpp"
#include "IGameModule.hpp"
#include "Menu.hpp"


namespace arcade {
    class Core
    {
    private:
        std::vector<std::string> _allLibGraph;
        std::vector<std::string>  _allGame;
        std::pair <int, int> _LibGame;
        IGraphicalLibrary *_Graphical;
        IGameModule *_Game;
        Menu *_menu;
        void *handleGame;
        void *handleGraph;
        int prevLib;
        int prevGame;
        std::vector<arcade::Input::Key> key;
        std::vector<arcade::GameObject> object;

    public:
        Core(void *handle);
        ~Core();
        void SetGraphical_and_Game(std::string path);
        std::vector<std::string> readdir_lib(std::string path);
        void launch_ncurses(void);
        void game_loop(int indexGraph, int indexGame);
        void menu(void);
        void load_game(int indexGame);
        void load_graphical(int indexGraph);
    };
}