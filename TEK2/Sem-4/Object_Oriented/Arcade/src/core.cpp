/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** core
*/

#include "core.hpp"

arcade::Core::Core(void *handle)
{
    SetGraphical_and_Game("./lib/");

    auto test = reinterpret_cast<arcade::IGraphicalLibrary *(*)()>(dlsym(handle, "entryPoint"));
    if (!test)
        throw Exception("Couldn't read library : " + std::string(dlerror()));
    this->_Graphical = test();

    this->prevGame = -1;
    this->prevLib = -1;
}

arcade::Core::~Core()
{
    dlclose(this->handleGame);
    dlclose(this->handleGraph);
}

void arcade::Core::SetGraphical_and_Game(std::string path)
{
    DIR *dir;
    struct dirent *diread;
    std::vector<std::string> lib = {
        "arcade_ncurses.so",
        "arcade_sdl2.so",
        "arcade_ndk++.so",
        "arcade_libcaca.so",
        "arcade_allegro5.so",
        "arcade_xlib.so",
        "arcade_gtk+.so",
        "arcade_sfml.so",
        "arcade_irrlicht.so",
        "arcade_opengl.so",
        "arcade_vulkan.so",
        "arcade_qt5.so"
    };

    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (strcmp(diread->d_name, "..") != 0 && strcmp(diread->d_name, ".") != 0 ) {
                if (std::find(lib.begin(), lib.end(), diread->d_name) != lib.end())
                    this->_allLibGraph.push_back(diread->d_name);
                else
                    this->_allGame.push_back(diread->d_name);
            }
        }
        closedir (dir);
    } else {
        perror ("opendir");
        exit(84);
    }
}

void arcade::Core::launch_ncurses(void)
{
    void *handle = dlopen("./arcade_menu.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << dlerror() << std::endl;
        throw std::runtime_error("Couldn't load menu");
    }
    auto func_sym = reinterpret_cast<arcade::Menu *(*)()>(dlsym(handle, "menu"));
    if (!func_sym) {
        std::cerr << dlerror() << std::endl;
        throw std::runtime_error("Couldn't get entryPoint symbol");
    }
    this->_menu = func_sym();
    return ;
}

void arcade::Core::load_graphical(int indexGraph)
{
    std::string lib = "./lib/" + this->_allLibGraph[indexGraph];
    this->handleGraph = dlopen(lib.c_str(), RTLD_LAZY);
    if (!this->handleGraph) {
        std::cerr << dlerror() << std::endl;
        throw std::runtime_error("Couldn't load library");
    }
    auto func_sym = reinterpret_cast<arcade::IGraphicalLibrary *(*)()>(dlsym(this->handleGraph, "entryPoint"));
    if (!func_sym) {
        std::cerr << dlerror() << std::endl;
        throw std::runtime_error("Couldn't get entryPoint symbol");
    }
    this->_Graphical = func_sym();
}

void arcade::Core::load_game(int indexGame)
{
    std::string lib = "./lib/" + this->_allGame[indexGame];
    this->handleGame = dlopen(lib.c_str(), RTLD_LAZY);
    if (!this->handleGame) {
        std::cerr << dlerror() << std::endl;
        throw std::runtime_error("Couldn't load library");
    }
    auto func_sym = reinterpret_cast<arcade::IGameModule *(*)()>(dlsym(this->handleGame, "entryPoint"));
    if (!func_sym) {
        std::cerr << dlerror() << std::endl;
        throw std::runtime_error("Couldn't get entryPoint symbol");
    }
    this->_Game = func_sym();
}

void arcade::Core::game_loop(int indexGraph, int indexGame)
{
    std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
    std::ofstream nibbler;
    std::ofstream pacman;

    if (this->prevLib != indexGraph) {
        load_graphical(indexGraph);
        this->_Graphical->init();
        this->prevLib = indexGraph;
    }
    if (this->prevGame != indexGame) {
        load_game(indexGame);
        this->_Game->init();
        this->prevGame = indexGame;
    }
    while (!this->_Game->is_over()) {
        this->key = this->_Graphical->get_input();
        if (this->key.size() != 0 && this->key[0] == arcade::Input::Unknown)
            continue ;
        if ((this->key.size() != 0 && this->key[0] == arcade::Input::Closed) || (this->key.size() != 0 && this->key[0] == arcade::Input::R)) {
            this->_Graphical->stop();
            break;
        }
        if (this->key.size() != 0 && this->key[0] == arcade::Input::U) {
            if ((indexGraph+1) < this->_allLibGraph.size()) {
                this->_Graphical->stop();
                dlclose(this->handleGraph);
                game_loop((indexGraph+1), indexGame);
             } else {
                this->_Graphical->stop();
                dlclose(this->handleGraph);
                game_loop(0, indexGame);
             }
        } else if (this->key.size() != 0 && this->key[0] == arcade::Input::Y) {
            if ((indexGraph-1) >= 0) {
                this->_Graphical->stop();
                dlclose(this->handleGraph);
                game_loop((indexGraph-1), indexGame);
            } else {
                this->_Graphical->stop();
                dlclose(this->handleGraph);
                game_loop((this->_allLibGraph.size()-1), indexGame);
            }
        } else if (this->key.size() != 0 && this->key[0] == arcade::Input::H) {
            if ((indexGame+1) < this->_allGame.size()) {
                if (this->_allLibGraph[indexGraph] == "arcade_ncurses.so")
                    this->_Graphical->stop();
                if (this->_allGame[indexGame] == "arcade_nibbler.so") {
                    nibbler.open("./scores_nibbler");
                    nibbler << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    nibbler.close();
                } else {
                    pacman.open("./scores_pacman");
                    pacman << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    pacman.close();
                }
                dlclose(this->handleGame);
                game_loop(indexGraph, (indexGame+1));
            } else {
                if (this->_allLibGraph[indexGraph] == "arcade_ncurses.so")
                    this->_Graphical->stop();
                if (this->_allGame[indexGame] == "arcade_nibbler.so") {
                    nibbler.open("./scores_nibbler");
                    nibbler << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    nibbler.close();
                } else {
                    pacman.open("./scores_pacman");
                    pacman << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    pacman.close();
                }
                dlclose(this->handleGame);
                game_loop(indexGraph, 0);
            }
        } else if (this->key.size() != 0 && this->key[0] == arcade::Input::J) {
            if ((indexGame-1) >= 0) {
                if (this->_allLibGraph[indexGraph] == "arcade_ncurses.so")
                    this->_Graphical->stop();
                if (this->_allGame[indexGame] == "arcade_nibbler.so") {
                    nibbler.open("./scores_nibbler");
                    nibbler << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    nibbler.close();
                } else {
                    pacman.open("./scores_pacman");
                    pacman << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    pacman.close();
                }
                dlclose(this->handleGame);
                game_loop(indexGraph, (indexGame-1));
            } else {
                if (this->_allLibGraph[indexGraph] == "arcade_ncurses.so")
                    this->_Graphical->stop();
                if (this->_allGame[indexGame] == "arcade_nibbler.so") {
                    nibbler.open("./scores_nibbler");
                    nibbler << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    nibbler.close();
                } else {
                    pacman.open("./scores_pacman");
                    pacman << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
                    pacman.close();
                }
                dlclose(this->handleGame);
                game_loop(indexGraph, (this->_allGame.size()-1));
            }
        }
        this->object = this->_Game->update(this->key);
        this->_Graphical->clear();
        for (size_t i = 0; i < this->object.size(); i++)
            this->_Graphical->draw(this->object[i]);
        this->_Graphical->display();
    
        a = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> work_time = a - b;

        if (work_time.count() < 200.0) {
            std::chrono::duration<double, std::milli> delta_ms(200.0 - work_time.count());
            auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
        }
        b = std::chrono::system_clock::now();
    }
    this->_Graphical->clear();
    this->_Graphical->stop();
    if (this->_allGame[indexGame] == "arcade_nibbler.so") {
        nibbler.open("./scores_nibbler");
        nibbler << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
        nibbler.close();
    } else {
        pacman.open("./scores_pacman");
        pacman << this->_menu->get_name().c_str() << " : " << std::to_string(this->_Game->get_score()).c_str();
        pacman.close();
    }
    menu();
}

void arcade::Core::menu(void)
{
    this->_LibGame = this->_menu->loop_menu(this->_allLibGraph, this->_allGame);
    this->prevLib = -1;
    this->prevGame = -1;
    game_loop(this->_LibGame.first, this->_LibGame.second);
}