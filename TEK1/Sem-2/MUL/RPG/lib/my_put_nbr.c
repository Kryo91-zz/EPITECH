/*
** EPITECH PROJECT, 2019
** MY_PUT_NBR
** File description:
** displays the number given as a paramater
*/

#include "../include/my_rpg.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

long my_put_nbr(long nb, int fd)
{
    if (nb < 0) {
        my_putchar('-', fd);
        nb = - nb;
        if (nb == 2147483648) {
            nb = nb;
        }
    }
    if (nb >= 10) {
        my_put_nbr(nb/10, fd);
        my_putchar(nb %10 + '0', fd);
    } else {
        my_putchar(nb +'0', fd);
    }
    return (0);
}