/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "../include/my_rpg.h"

int main(int ac, char **av)
{
    glb_t *global = malloc(sizeof(glb_t));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        doc();
    rpg_loop(global);
    return (0);
}