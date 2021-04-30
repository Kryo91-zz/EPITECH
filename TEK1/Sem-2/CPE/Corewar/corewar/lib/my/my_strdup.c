/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicates a string in a new area
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * (len + 1));
    dest[len] = 0;
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
    return (dest);
}
