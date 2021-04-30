/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** alphanum_test.c
*/

#include <stdbool.h>

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (true);
    if (c >= 'A' && c <= 'Z')
        return (true);
    if (c == '_')
        return (true);
    return (false);
}

int alpha_test(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!is_alpha(str[i]))
            return (1);
    return (0);
}