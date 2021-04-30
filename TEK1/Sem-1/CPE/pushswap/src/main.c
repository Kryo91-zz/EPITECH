/*
** EPITECH PROJECT, 2019
** PUSH_SWAP
** File description:
** .c
*/

#include "../inc/push_swap.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i = 1;
    char *str = av[i];
    char *dest = av[i+1];
    char *src = av[ac-1];

    if (ac < 2)
        return (84);
    if (ac == 2) {
        my_putchar('\n');
        return (0);
    }
    sort(str, dest, src, av);
    my_putchar('\n');
    return (0);

}

void sort(char *str, char *dest, char *src, char **av)
{
    for (int i = 1; av[i+1] != NULL;) {
        if (my_getnbr(str) <= my_getnbr(dest)) {
            ++i;
        }
        if (my_getnbr(str) > my_getnbr(src)) {
            my_putstr("rra");
            ++i;
        }
    }
}