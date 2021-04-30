/*
** EPITECH PROJECT, 2019
** lib
** File description:
** blank_str.c
*/

#include <stdbool.h>

bool str_is_blank(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return ((int)str[i]);
    }
    return (false);
}