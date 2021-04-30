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

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\n'; ++i);

    return (i);
}

void destroy_dante(char **map)
{
    for (int i = 0; map[i] != NULL; ++i) {
        free(map[i]);
    }
    free(map);
}

void draw_map(char **map)
{
    int index = 0;
    map[solv->hight-1][solv->width-1] = 'o';
    for (; map[index] != NULL; ++index) {
        map[index][strlen(map[index])] = '\n';
        if (map[index+1] == NULL)
            map[index][strlen(map[index])-1] = '\0';
        printf("%s", map[index]);
    }
}