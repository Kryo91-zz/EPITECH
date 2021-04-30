/*
** EPITECH PROJECT, 2019
** MY_IS_PRIME
** File description:
** find the first prime number
*/

#include "../inc/my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb == 0 || nb == 1) {
        return (0);
    }
    while (i <= nb) {
        if (nb % i == 0) {
            return (0);
        }
        i = i + 1;
    }
    return (1);

}
