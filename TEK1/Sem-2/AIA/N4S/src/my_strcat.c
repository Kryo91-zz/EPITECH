/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    char *tmp = NULL;
    size_t i = 0;

    if (src == NULL)
        return (dest);
    if (dest == NULL || dest[0] == 0) {
        dest = malloc(sizeof(char) * (strlen(src) + 1));
        strcpy(dest, src);
        return (dest);
    }
    tmp = malloc(sizeof(char) * (strlen(src) + strlen(dest) + 1));
    for (; dest[i]; i++)
        tmp[i] = dest[i];
    for (int j = 0; src[j]; j++)
        tmp[i++] = src[j];
    tmp[i] = 0;
    return (tmp);
}