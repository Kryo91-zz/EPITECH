/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** n-curse.c
*/

#include "../inc/my.h"

WINDOW *create_new_board(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    wborder(win, '¯', '¯', '¯', '¯', '¯', '¯', '¯', '¯');
    return (win);
}

WINDOW *create_new_boarrd(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    i_s();
    return (win);
}

WINDOW *create_new_boarrrd(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    wborder(win, '¯', '¯', '¯', '¯', '¯', '¯', '¯', '¯');
    score();
    return (win);
}

WINDOW *create_new_boarrrrd(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    next(start_x);
    wborder(win, '¯', '¯', '¯', '¯', '¯', '¯', '¯', '¯');
    return (win);
}