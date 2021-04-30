/*
** EPITECH PROJECT, 2019
** MY_STR_ISPRINTABLE
** File description:
** str_islower
*/

#include "../inc/my.h"

int my_str_isprintable(char const *str)
{
    int i = -1;
    int is_print = 1;

    while (str[(i = i + 1)] != '\0' && is_print)
        if (str[i] < 32)
        is_print = 0;
    return (is_print);

}
