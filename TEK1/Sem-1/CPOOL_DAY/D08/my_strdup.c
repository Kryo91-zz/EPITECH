/*
** EPITECH PROJECT, 2019
** MY_STRDUP
** File description:
** allocates memory and copies the string given as argument
*/
#include <stdlib.h>

int my_strlen(char const *str);

char    *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * ((my_strlen(src) +1)));

    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}
