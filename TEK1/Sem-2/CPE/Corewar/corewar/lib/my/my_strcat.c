/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char const *dest, char const *src)
{
    char *tmp = NULL;
    size_t i = 0;

    if (src == NULL)
        return (my_strdup(dest));
    if (dest == NULL || dest[0] == 0)
        return (my_strdup(src));
    tmp = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
    for (; dest[i]; i++)
        tmp[i] = dest[i];
    for (int j = 0; src[j]; j++)
        tmp[i++] = src[j];
    tmp[i] = 0;
    return (tmp);
}

char *my_freecat(char *dest, char *src)
{
    char *tmp = NULL;
    size_t i = 0;

    if (src == NULL)
        return (ptr_message("", my_strdup(dest), 1, dest));
    if (dest == NULL || dest[0] == 0)
        return (ptr_message("", my_strdup(src), 1, src));
    tmp = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
    for (; dest[i]; i++)
        tmp[i] = dest[i];
    for (int j = 0; src[j]; j++)
        tmp[i++] = src[j];
    tmp[i] = 0;
    free(dest);
    free(src);
    return (tmp);
}