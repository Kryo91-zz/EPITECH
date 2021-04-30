/*
** EPITECH PROJECT, 2019
** MY_SWAP
** File description:
** swap the content of two integers, whose addresses are given in parameter
*/
#include "../inc/my.h"

void    my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
