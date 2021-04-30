/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** str_num
*/

#include "../inc/my.h"

int my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] > 47 && str[i] < 58))
            ++i;
        else
            return (1);
    }
    return (0);
}
