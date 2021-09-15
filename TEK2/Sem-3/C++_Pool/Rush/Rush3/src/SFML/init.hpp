/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** init.hpp
*/

#ifndef INIT_HPP_
#define INIT_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class colonne_1
{
    protected:
        int x;
        int y;
        int pos;
};

class colonne_2
{
    int x;
    int y;
    int pos;
};

class line
{
    protected:
        int background;
    public:
        line();
        ~line();
};

#endif