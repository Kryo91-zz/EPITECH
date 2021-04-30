/*
** EPITECH PROJECT, 2019
** lib
** File description:
** check_str_empty.c
*/

#include "my.h"

int check_str_empty(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return ((int)str[i]);
    }
    return (0);
}