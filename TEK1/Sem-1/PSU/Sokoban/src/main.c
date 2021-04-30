/*
** EPITECH PROJECT, 2019
** MY_SOKOBAN
** File description:
** .c
*/

#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "../inc/my_sokoban.h"

int main(int ac, char **av)
{
    if (description(ac, av) == 1)
        return (0);
    if (ac != 2)
        return (84);
    if (reader(av) == 84)
        return (84);
}

int description(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "USAGE\n     ./my_sokoban map\n", 29);
        write(1, "DESCRIPTION\n     map file representing the ", 44);
        write(1, "warehouse map, containing '#' for walls, \n   ", 56);
        write(1, "    'P' for the player, 'X' for boxes and 'O' ", 47);
        write(1, "for storage locations.", 23);
        return (1);
    }
    return (0);
}