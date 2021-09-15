/*
** EPITECH PROJECT, 2020
** tab_to_2dtab
** File description:
** tab_to_2dtab.c
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    *res = malloc(length * sizeof(int) * 4096);
    for (int i = 0, j = 0; i < length; ++i) {
        j = 0;
        (*res)[i] = malloc(width * sizeof(int) * 4096);
        for (;j < width; ++j)
            (*res)[i][j] = tab[i*width+j];
    }
}