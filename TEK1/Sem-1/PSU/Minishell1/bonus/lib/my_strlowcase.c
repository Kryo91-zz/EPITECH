/*
** EPITECH PROJECT, 2019
** MY_STRLOWCASE
** File description:
** strlowcase
*/

#include "../inc/my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i = i + 1;
    }
    return (str);
}
