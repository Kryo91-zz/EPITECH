/*
** EPITECH PROJECT, 2019
** CPE_matchstick_bootstrap_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    int i = my_str_isnum(av[1]);
    int j = my_str_isnum(av[2]);
    if (i == 1 || j == 1)
        return (84);
    int len = my_getnbr(av[1])* 2 + 1;
    int lines = my_getnbr(av[1]) + 2;
    char **play = map(len, lines);
    return (print_game_return_game(0, 0, play, av));
}
