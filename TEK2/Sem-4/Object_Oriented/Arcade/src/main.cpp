/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** main
*/

#include "Include.hpp"
#include "IGraphicalLibrary.hpp"
#include "IGameModule.hpp"
#include "core.hpp"


void *readlib(std::string filepath)
{
    void *handle;
    std::string handler = "./";

    if (filepath.length() < filepath.find_last_of(".") + 2 ||\
    filepath[filepath.find_last_of(".") + 1] != 's' ||\
    filepath[filepath.find_last_of(".") + 2] != 'o')
        throw Exception("no dynamic library found");
    if(filepath.substr(0,2) != "./") {
        handler += filepath;
        handle = dlopen(handler.c_str(), RTLD_LAZY);
    } else
        handle = dlopen(filepath.c_str(), RTLD_LAZY);
    if (!handle)
        throw Exception("Couldn't open library : " + std::string(dlerror()));
    return(handle);
}

int main(int argc, char **argv)
{
    void *first_handle;

    if (argc != 2) {
        std::cout << "Usage: ./arcade ./lib/\"Graphical library of your choice\"" << std::endl;
        return(84);
    }
    try {
        first_handle = readlib(argv[1]);
        arcade::Core func(first_handle);
        func.launch_ncurses();
        func.menu();
    } catch(Exception &e) {
        std::cout << e.what() << std::endl;
        return(84);
    }
    dlclose(first_handle);
    return(0);
}