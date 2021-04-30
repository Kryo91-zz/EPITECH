/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string to another location
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int c = 0;

    if (!src || !dest)
        return (NULL);
    while (src[c] != '\0') {
        dest[c] = src[c];
        c++;
    }
    dest[c] = 0;
    return (dest);
}
