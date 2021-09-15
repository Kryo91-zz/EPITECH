/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex04.cpp
*/

#include "ex04.hpp"

bool equal(const int a, const int b) {return (a == b);}
bool equal(const float a, const float b) {return (a == b);}
bool equal(const double a, const double b) {return (a == b);}
bool equal(const std::string a, const std::string b) {return (strcmp(a.c_str(), b.c_str()) == 0);}

template <> bool Tester<int>::equal(const int &a, const int &b) {return (a == b);}
template <> bool Tester<float>::equal(const float &a, const float &b) {return (a == b);}
template <> bool Tester<double>::equal(const double &a, const double &b) {return (a == b);}
template <> bool Tester<std::string>::equal(const std::string &a, const std::string &b) {return (strcmp(a.c_str(), b.c_str()) == 0);}
