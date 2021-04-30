/*
** EPITECH PROJECT, 2019
** ls
** File description:
** my_strdup
*/

#include "../inc/my.h"

char    *my_strdup(char const *src)
{
    char    *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
    free(dest);
}