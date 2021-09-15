/*
** EPITECH PROJECT, 2020
** menger
** File description:
** menger.c
*/

#include "menger.h"

void comp_fractal(int size, int lvl, bool menger, int first_mid[2])
{
    int lvl_size = size / 3;
    int new_offset[2] = {1, 1};
    int mid[2] = {lvl_size + first_mid[0], lvl_size + first_mid[1]};

    if (lvl_size == 0 || lvl == 0 || !menger)
        return;
    printf("%03d %03d %03d\n", lvl_size, (lvl_size + first_mid[0]), \
    (lvl_size + first_mid[1]));
    for (int x = first_mid[0]; x - first_mid[0] < size; x = x+(size/3)) {
        for (int y = first_mid[1]; y - first_mid[1] < size; y = y+(size/3)) {
            new_offset[0] = x;
            new_offset[1] = y;
            menger = mid[0] == new_offset[0] && mid[1] == new_offset[1];
            comp_fractal(lvl_size, lvl-1, !menger, new_offset);
        }
    }
    return;
}

int check_error(int ac, char **av)
{
    if (ac != 3 || atoi(av[1]) % 3 != 0 || atoi(av[2]) < 0 || atoi(av[1]) == 0)
        return (1);
    return (0);
}

void check_lvl(char **av)
{
    int size = atoi(av[1]);
    int lvl = atoi(av[2]);
    int first_mid[2] = {0, 0};

    if (lvl == 0) {
        printf("000 000 000\n");
        exit(0);
    }
    comp_fractal(size, lvl, true, first_mid);
    return ;
}