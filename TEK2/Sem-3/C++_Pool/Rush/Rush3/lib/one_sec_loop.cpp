/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** time_update.cpp
*/

#include "one_sec_loop.hpp"

void one_sec_loop(loop_func_t disp, SysData data)
{
    size_t last_tic = time(nullptr);
    char key = 0;

    while (key != 27) {
        size_t tmp_tic = time(nullptr);
        if (tmp_tic > last_tic) {
            last_tic = tmp_tic;
            disp(last_tic, data);
            data.refreshData();
        }
        key = getch();
    }
    curs_set(1);
}