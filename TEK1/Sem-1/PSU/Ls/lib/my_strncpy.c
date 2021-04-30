/*
** EPITECH PROJECT, 2019
** MY_STRNCPY
** File description:
** write a function that copy a strin of n character into another
*/

#include "../inc/my.h"

char     *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n < i)
        dest[i] = '\0';
    return (dest);
}
