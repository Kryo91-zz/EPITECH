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
        if ((str[i] > 47 && str[i] < 58) || (str[i] < 123 && str[i] > 96) ||
            (str[i] > 64 && str[i] < 91) || str[i] == ' ')
            ++i;
        else
            return (1);
    }
    return (0);
}