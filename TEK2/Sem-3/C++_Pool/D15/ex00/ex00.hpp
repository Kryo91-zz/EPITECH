/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex00.hpp
*/

#ifndef EX00_HPP_
    #define EX00_HPP_

    #define COUT std::cout
    #define ENDL std::endl

#include <iostream>

template <typename T>

void swap(T &A, T &B)
{
    T swap;
    swap = A;
    A = B;
    B = swap;
}

template <typename T>

T &min(T &A, T &B)
{
    if (A < B)
        return A;
    else
        return B;
}

template <typename T>

T &max(T &A, T &B)
{
    if (A > B)
        return A;
    else
        return B;
}

template <typename T>

T add(T &A, T &B)
{
    return A + B;
}

#endif