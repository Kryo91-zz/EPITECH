/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-tekspice-lyvia.mallereau
** File description:
** main.cpp
*/

#include "../inc/lib_included.hpp"
#include "../inc/IComponent.hpp"
#include "Parser.hpp"

bool and_gate ( bool a , bool b )
{
    return a && b ;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    try {
        nts::Parser p(av[1]);
    } catch (const nts::Exception &e) {
        std::cout << e.what() << std::endl;
        exit(84);
    }
    
}