/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex04.hpp
*/

#ifndef EX04_HPP_
    #define EX04_HPP_
    #define COUT std::cout
    #define ENDL std::endl

#include <iostream>
#include <string>
#include <cstring>


template <typename T>
class Tester
{
    public :
        bool equal(const T &A, const T &B);
};

bool equal(const int a, const int b);
bool equal(const float a, const float b);
bool equal(const double a, const double b);
bool equal(const std::string a, const std::string b);

#endif