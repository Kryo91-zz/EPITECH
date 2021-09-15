/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex00.hpp
*/

#ifndef EX01_HPP_
    #define EX01_HPP_

    #define COUT std::cout
    #define ENDL std::endl

#include <iostream>
#include <cstring>

template <typename T>
int compare(const T &A, const T &B)
{

    if (A > B)
        return 1;
    else if (A == B)
        return (0);
    else
        return (-1);
}

template <>
int compare(const char * const &str, const char * const &src)
{
    int res = strcmp(str, src);

    if (res > 0)
        return 1;
    else if (res == 0)
        return (0);
    else
        return (-1);
}

#endif