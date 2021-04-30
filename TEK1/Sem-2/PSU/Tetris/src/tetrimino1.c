/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetrimino1.c
*/

#include "../inc/my.h"

void swap_tetrimino(char **map, char *tmp, int j)
{
    if (map[j+1] != NULL && my_strcmp(map[j], map[j+1]) > 0) {
        tmp = map[j];
        map[j] = map[j+1];
        map[j+1] = tmp;
        tmp = NULL;
    }

}

char **sort_tetrimino2(char **map, char *tmp)
{
    for (int j = 0; map[j] != NULL; ++j)
        swap_tetrimino(map, tmp, j);
    for (int j = 0; map[j] != NULL; ++j)
        swap_tetrimino(map, tmp, j);
    return (map);
}

char **sort_tetrimino(DIR *oth)
{
    char **map = malloc(sizeof(char *) * 4096);
    struct dirent *directo;
    int i = 0;
    char *tmp = malloc(sizeof(char) * 4096);

    while ((directo = readdir(oth)) != NULL) {
        if ((directo->d_name[0] != '.')) {
            map[i] = directo->d_name;
            ++i;
        }
    }
    map[i+1] = NULL;
    for (int j = 0; map[j] != NULL; ++j)
        swap_tetrimino(map, tmp, j);
    return (sort_tetrimino2(map, tmp));
}