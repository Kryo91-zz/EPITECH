/*
** EPITECH PROJECT, 2019
** MY_STRCPY
** File description:
** write a function that copy a string into another
*/

#include "../inc/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
