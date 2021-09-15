/*
** EPITECH PROJECT, 2020
** menger
** File description:
** main.c
*/

#include "menger.h"

int main(int ac, char **av)
{
    if (check_error(ac, av) == 1)
        return (84);
    check_lvl(av);
    return (0);
}