/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex02.hpp
*/



#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template <typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return (a);
    return (b);
}

template <typename T>
const T &templateMin(T *array, int size)
{
    T &comp = array[0];

    for (int i = 1; i < size; i += 1) {
        comp = min(comp, array[i]);
    }
    return (comp);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return (a);
    return (b);
}

int nonTemplateMin(int *array, int size)
{
    int comp = array[0];

    for (int i = 1; i < size; i += 1) {
        comp = min(comp, array[i]);
    }
    return (comp);
}

#endif /* !EX02_HPP_ */