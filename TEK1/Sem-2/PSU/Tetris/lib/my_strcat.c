/*
** EPITECH PROJECT, 2019
** MY_STRCAT
** File description:
** add another to the following first one
*/

#include "../inc/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[i] = src[j];
        ++i;
        ++j;
    }
    dest[i] = '\0';
    return (dest);
}