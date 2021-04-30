/*
** EPITECH PROJECT, 2020
** CPE_Dante_2019
** File description:
** print_map
*/

#include "generator.h"

void print_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        printf("%s", map[i]);
        i = i + 1;
    }
}