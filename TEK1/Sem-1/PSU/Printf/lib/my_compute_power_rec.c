/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_POWER_REC
** File description:
** a recurcive function thats return the first argument raised to the power p
*/

#include "../inc/my.h"

int my_compute_power_rec(int nb, int p)
{
    int res;

    if (p == 0) {
        return (1);
    }
    if (nb == 0 || p == 1){
        return (nb);
    }
        if (p < 0) {
            return (0);
        }
    res = nb * my_compute_power_rec(nb, p - 1);
    return (res);
}
