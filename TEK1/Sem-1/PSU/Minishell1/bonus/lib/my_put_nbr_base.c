/*
** EPITECH PROJECT, 2019
** MY_PRINTF
** File description:
** Printf base
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/my.h"

int my_putnbr_base(int nbr, char *base)
{
    int count = 0;
    char *str = malloc(sizeof(*str));
    if (nbr < 0)
        nbr *= -1;
    for (int i = 0; nbr > 0; i += 1) {
        count = nbr % my_strlen(base);
        str[i] = base[count];
        nbr /= my_strlen(base);
    }
    my_revstr(str);
    for (int j = 0; str[j] != 0; j += 1) {
        my_putchar(str[j]);
    }
    free(str);
    return (0);
}