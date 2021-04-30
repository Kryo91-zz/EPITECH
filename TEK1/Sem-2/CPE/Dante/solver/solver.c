/*
** EPITECH PROJECT, 2019
** CPE_date_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

int solver_maze3(char **map, int j, int i, int n)
{
    if (j-1 >= 0 && map[j-1][i] == '*') {
        map[j][i] = 'o';
        solv->r = solver_maze(map, j - 1, i, n + 1);
        if (solv->r == 0)
            return (0);
        map[j][i] = '*';
    }
    return (1);
}

int solver_maze2(char **map, int j, int i, int n)
{
    if (i+1 <= solv->width-1 && map[j][i+1] == '*') {
        map[j][i] = 'o';
        solv->r = solver_maze(map, j, i + 1, n + 1);
        if (solv->r == 0)
            return (0);
        map[j][i] = '*';
    }
    if (i-1 >= 0 && map[j][i-1] == '*' ) {
        map[j][i] = 'o';
        solv->r = solver_maze(map, j, i - 1, n + 1);
        if (solv->r == 0)
            return (0);
        map[j][i] = '*';
    }
    return (solver_maze3(map, j, i, n));
}

int solver_maze(char **map, int j, int i, int n)
{
    solv->r = 0;

    if (n > 10000000)
        exit(84);
    if (j == solv->hight-1 && i == solv->width-1) {
        map[j][i] = 0;
        return (0);
    } else {
        if (j+1 <= solv->hight-1 && map[j+1][i] == '*') {
            map[j][i] = 'o';
            solv->r = solver_maze(map, j + 1, i, n + 1);
            if (solv->r == 0)
                return (0);
            map[j][i] = '*';
        }
        return (solver_maze2(map, j, i, n));
    }
    return (0);
}