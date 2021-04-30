/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_putnbr_base.c
*/

#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);

void my_putchar(char c);

int my_putnbr_base(long long nbr, char const *base)
{
    int b = my_strlen(base);

    if (nbr >= b)
        my_putnbr_base(nbr / b, base);
    my_putchar(base[nbr%b]);
    return (0);
}