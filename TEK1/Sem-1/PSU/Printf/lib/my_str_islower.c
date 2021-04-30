/*
** EPITECH PROJECT, 2019
** MY_STR_ISLOWER
** File description:
** str_islower
*/

#include "../inc/my.h"

int my_str_islower(char const *str)
{
    int i = -1;
    int is_lower = 1;

    while (str[(i = i + 1)] != '\0')
        if (!(str[i] > 96 && str[i] < 123))
        is_lower = 0;
    return (is_lower);
}
