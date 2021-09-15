/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** one_sec_loop.hpp
*/

#ifndef ONE_SEC_LOOP_HPP_
    #define ONE_SEC_LOOP_HPP_

    #include "lib.hpp"
    #include "my_ncurses.hpp"

    using loop_func_t = void (*)(int, SysData);

    void one_sec_loop(loop_func_t func, SysData data);

#endif