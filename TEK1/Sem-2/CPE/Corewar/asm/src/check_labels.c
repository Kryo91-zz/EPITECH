/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_labels.c
*/

#include "asm.h"

bool contains_spaces(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            return (true);
    return (false);
}

bool str_contains(char const *str, char const c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (true);
    return (false);
}

bool is_right_chars(char const *str, char const *right_chars)
{
    for (int i = 0; str[i]; i++) {
        if (!str_contains(right_chars, str[i]))
            return (false);
    }
    return (true);
}