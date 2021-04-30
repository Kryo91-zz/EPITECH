/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** title.c
*/

#include "../inc/my.h"

void t_e(void)
{
    attron(COLOR_PAIR(1));
    mvprintw(1, 1, "#####");
    mvprintw(2, 3, "#");
    mvprintw(3, 3, "#");
    mvprintw(4, 3, "#");
    mvprintw(5, 3, "#");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(1, 7, "#####");
    mvprintw(2, 7, "#");
    mvprintw(3, 7, "###");
    mvprintw(4, 7, "#");
    mvprintw(5, 7, "#####");
    attroff(COLOR_PAIR(2));
}

void t_r(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(1, 13, "#####");
    mvprintw(2, 15, "#");
    mvprintw(3, 15, "#");
    mvprintw(4, 15, "#");
    mvprintw(5, 15, "#");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    mvprintw(1, 19, "#####");
    mvprintw(2, 19, "#   #");
    mvprintw(3, 19, "####");
    mvprintw(4, 19, "#   #");
    mvprintw(5, 19, "#   #");
    attroff(COLOR_PAIR(4));
}

void i_s(void)
{
    t_e();
    t_r();
    attron(COLOR_PAIR(5));
    mvprintw(1, 25, "#");
    mvprintw(3, 25, "#");
    mvprintw(4, 25, "#");
    mvprintw(5, 25, "#");
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(6));
    mvprintw(1, 27, "#####");
    mvprintw(2, 27, "#");
    mvprintw(3, 27, "#####");
    mvprintw(4, 27, "    #");
    mvprintw(5, 27, "#####");
    attroff(COLOR_PAIR(6));
}

void score(void)
{
    mvprintw(9, 3, "High Score:");
    mvprintw(10, 3, "Score:");
    mvprintw(12, 3, "Lines:");
    mvprintw(13, 3, "Level:");
    mvprintw(15, 3, "Timer:");
}

void next(int len)
{
    mvprintw(1, len, "Next:");
}