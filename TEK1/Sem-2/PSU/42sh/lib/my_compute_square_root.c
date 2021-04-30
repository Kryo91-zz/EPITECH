/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_SQUARE_ROOT
** File description:
** function that returns the square root of the number given as argument
*/

#include "../inc/my.h"

int my_compute_square_root(int nb)
{
    int a = 0;

    if (nb < 0 || nb == 0) {
        return (0);
    }

    while (a * a != nb) {
        a = a + 1;
        if (a > nb) {
            return (0);
        }
    }
    return (a);
}