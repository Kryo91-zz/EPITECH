/*
** EPITECH PROJECT, 2020
** generator
** File description:
** imperfect_maze
*/

#include "generator.h"

void destroy_dante(char **map)
{
    for (int i = 0; map[i] != NULL; ++i) {
        free(map[i]);
    }
    free(map);
}

char **create_imperfect3(char **maze, int x, int y)
{
    int rando = 0;

    for (int j = 0, count = 0; maze[j] != NULL; j+=1) {
        rando = rand();
        if (j % 2 == 1) {
            maze[j][rando%x] = '*';
            maze[j][rando%(x-3)] = '*';
            maze[j][rando%(x-5)] = '*';
            maze[j][rando%(x-1)] = '*';
            maze[j][rando%(x-7)] = '*';
            maze[j][rando%(x-4)] = '*';
            maze[j][rando%(x-6)] = '*';
            maze[j][rando%(x-2)] = '*';
        }
    }
    maze[y-1][x-1] = '*';
    return (maze);
}

char **create_imperfect2(char **maze, int x, int y)
{
    int count = 0;

    for (int j = 0; maze[j] != NULL; j+=1) {
        if (j % 2 == 1 && count % 2 == 0) {
            maze[j][x-1] = '*';
            ++count;
        } else if (j % 2 == 1 && count % 2 == 1) {
            maze[j][0] = '*';
            ++count;
        }
    }
    maze[y-1][x-1] = '*';
    return (create_imperfect3(maze, x, y));
}

char **create_imperfect(char **maze, int x, int y)
{
    int i = 0;

    for (int j = 0; maze[j] != NULL; ++j) {
        for (; maze[j][i] != '\n' && maze[j][i] != '\0'; ++i) {
            if (j % 2 == 0)
                maze[j][i] = '*';
        }
        i = 0;
    }
    return (create_imperfect2(maze, x, y));
}

void imperfect_maze(int i, int j)
{
    char **maze = malloc(sizeof(char *) * 4096);
    maze = fill_maze(i, j, maze);
    maze = create_imperfect(maze, i, j);
    print_map(maze);
    destroy_dante(maze);
}
