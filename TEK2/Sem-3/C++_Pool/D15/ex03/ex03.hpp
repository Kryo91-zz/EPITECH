/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex03.hpp
*/

#ifndef EX03_HPP_
    #define EX03_HPP_

    #define COUT std::cout
    #define ENDL std::endl

#include <iostream>

template <typename T>
void print(const T &a)
{
    COUT << a << ENDL;
}

template <typename T>
void foreach(const T *tab, void (*func)(const T &elem), int size)
{
    for (int i = 0; i < size; ++i)
        func(tab[i]);
}

#endif