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

void cpy_map(char *str, char ***tab, player_t *posi)
{
    int j = 0;
    int count = 0;
    int count2 = 0;

    for (; str[j] != '\0'; ++j) {
        if (str[j] == '\n') {
            ++count2;
            count = 0;
        } else {
            (*tab)[count2][count] = str[j];
            coor_rec(tab, posi, count2, count);
            ++count;
        }
    }
}

void coor_rec(char ***tab, player_t *posi, int count2, int count)
{
    if ((*tab)[count2][count] == 'P') {
        posi->y = count2;
        posi->x = count;
    }
    if ((*tab)[count2][count] == 'O') {
        posi->yo = count2;
        posi->xo = count;
    }
    if ((*tab)[count2][count] == 'X') {
        posi->yx = count2;
        posi->xx = count;
    }
}