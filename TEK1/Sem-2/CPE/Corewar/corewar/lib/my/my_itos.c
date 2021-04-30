/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** itos.c
*/

#include <stdlib.h>

int len_number(int nb)
{
    size_t len = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        len += 1;
        nb *= -1;
    }
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

char *my_itos(long long nb)
{
    long long tmp = nb;
    char *str = NULL;
    size_t len = len_number(nb);
    int stop = 0;

    str = malloc(sizeof(char) * (len + 1));
    str[len] = 0;
    if (nb < 0) {
        str[0] = '-';
        nb *= -1;
        stop = 1;
    }
    for (int i = len - 1; i >= stop; i--) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
    }
    return (str);
}