/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** find.hpp
*/

#ifndef FIND_HPP_
    #define FIND_HPP_

    #include <iostream>
    #include <algorithm>


template <typename T>
typename T::iterator do_find(T &tab, int find)
{
    // int nb = 0;

    // //std::cout << "DEBUG" << std::endl;
    // for (; tab; ++nb) {
    //     if ((int)tab[nb] == find)
    //         return nb;
    //     std::cout << "tab[nb] = " << (int)tab[nb] << std::endl;
    // }
    // return nb;
    return std::find(tab.begin(), tab.end(), find);

}

#endif