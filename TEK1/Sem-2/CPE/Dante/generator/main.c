/*
** EPITECH PROJECT, 2019
** CPE_date_2019
** File description:
** main.c
*/

#include "generator.h"

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;

    if (ac == 3 && (atoi(av[1]) != 0) && (atoi(av[2]) != 0)) {
        i = atoi(av[1]);
        j = atoi(av[2]);
        imperfect_maze(i, j);
    } else if (ac == 4 && ((atoi(av[1]) > 0) && (atoi(av[2]) > 0)) &&
                strcmp(av[3], "perfect") == 0) {
        i = atoi(av[1]);
        j = atoi(av[2]);
        perfect_maze(i, j);
    } else
        return (84);

    return (0);
}

char **fill_maze(int x, int y, char **maze)
{
    int i = 0;
    int j = 0;

    while (i < y) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        for (j = 0; j < x; ++j) {
            maze[i][j] = 'X';
        }
        maze[i][x] = '\n';
        ++i;
    }
    maze[i - 1][j] = '\0';
    maze[y] = NULL;
    return (maze);
}