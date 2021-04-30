/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** give array length
*/

#include <stdlib.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    if (!str)
        return (0);
    while (str[i])
        i += 1;
    return (i);
}
