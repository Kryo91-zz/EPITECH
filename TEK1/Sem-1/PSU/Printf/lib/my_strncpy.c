/*
** EPITECH PROJECT, 2019
** MY_STRNCPY
** File description:
** write a function that copy a strin of n character into another
*/

#include "../inc/my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    char carac;

    carac = 0;
    while (carac < n && src[carac] != '\0')
    {
        dest[carac] = src[carac];
        carac = carac + 1;
    }
    if (n <= carac)
    {
        dest[carac] = '\0';
    }
    return (dest);
}
