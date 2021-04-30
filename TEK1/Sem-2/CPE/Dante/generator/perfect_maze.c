/*
** EPITECH PROJECT, 2020
** generator
** File description:
** perfect_maze
*/

#include "generator.h"

void perfect_maze(int i, int j)
{
    char **maze = malloc(sizeof(char *) * (j + 5));
    maze = fill_maze(i, j, maze);
    maze = create_perfect(maze, i, j);
    print_map(maze);
    destroy_dante(maze);
}

char **create_perfect(char **maze, int x, int y)
{
    int i = 0;
    int count = 0;

    for (int j = 0; maze[j] != NULL; ++j) {
        for (; maze[j][i] != '\n' && maze[j][i] != '\0'; ++i) {
            if (j % 2 == 0)
                maze[j][i] = '*';
        }
        i = 0;
    }
    for (int j = 0; maze[j] != NULL; j += 1) {
        if (j % 2 == 1 && count % 2 == 0) {
            maze[j][x-1] = '*';
            ++count;
        } else if (j % 2 == 1 && count % 2 == 1) {
            maze[j][0] = '*';
            ++count;
        }
    }
    maze[y-1][x-1] = '*';
    return (maze);
}