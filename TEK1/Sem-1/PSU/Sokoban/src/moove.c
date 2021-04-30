/*
** EPITECH PROJECT, 2019
** MY_SOKOBAN
** File description:
** .c
*/

#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "../inc/my_sokoban.h"

void moove_start_close(int key, char **tab, player_t *posi)
{

    tab[posi->y][posi->x] = ' ';
    tab[posi->yo][posi->xo] = 'O';

    if (key == 'z' || key == KEY_UP)
        mouv_up(tab, posi);
    if (key == 'q' || key == KEY_LEFT)
        mouv_left(tab, posi);
    if (key == 's' || key == KEY_DOWN)
        mouv_down(tab, posi);
    if (key == 'd' || key == KEY_RIGHT)
        mouv_right(tab, posi);

    tab[posi->y][posi->x] = 'P';
    if (tab[posi->yo][posi->xo] == 'X') {
        tab[posi->yo][posi->xo] = 'X';
        endwin();
        exit (0);
    } else
        tab[posi->yo][posi->xo] = 'O';
}

void    mouv_up(char **tab, player_t *posi)
{
    if (tab[posi->y - 1][posi->x] == '#')
        return ;
    if (tab[posi->y - 1][posi->x] == 'X') {
        if (tab[posi->y - 2][posi->x] == '#' ||
            tab[posi->y - 2][posi->x] == 'X')
            return ;
        tab[posi->y - 1][posi->x] = ' ';
        tab[posi->y - 2][posi->x] = 'X';
        posi->y -= 1;
    } else
        posi->y -= 1;
}

void    mouv_down(char **tab, player_t *posi)
{
    if (tab[posi->y + 1][posi->x] == '#')
        return ;
    if (tab[posi->y + 1][posi->x] == 'X') {
        if (tab[posi->y + 2][posi->x] == '#' ||
            tab[posi->y + 2][posi->x] == 'X')
            return ;
        tab[posi->y + 1][posi->x] = ' ';
        tab[posi->y + 2][posi->x] = 'X';
        posi->y += 1;
    } else
        posi->y += 1;
}

void    mouv_right(char **tab, player_t *posi)
{
    if (tab[posi->y][posi->x + 1] == '#')
        return ;
    if (tab[posi->y][posi->x + 1] == 'X') {
        if (tab[posi->y][posi->x + 2] == '#' ||
            tab[posi->y][posi->x + 2] == 'X')
            return ;
        tab[posi->y][posi->x + 1] = ' ';
        tab[posi->y][posi->x + 2] = 'X';
        posi->x += 1;
    } else
        posi->x += 1;
}

void    mouv_left(char **tab, player_t *posi)
{
    if (tab[posi->y][posi->x - 1] == '#')
        return ;
    if (tab[posi->y][posi->x - 1] == 'X') {
        if (tab[posi->y][posi->x - 2] == '#' ||
            tab[posi->y][posi->x - 2] == 'X')
            return ;
        tab[posi->y][posi->x - 1] = ' ';
        tab[posi->y][posi->x - 2] = 'X';
        posi->x -= 1;
    } else
        posi->x -= 1;
}