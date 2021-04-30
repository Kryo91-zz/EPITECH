/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** counts and returns the number of characters in the string
*/

#include <stdlib.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
