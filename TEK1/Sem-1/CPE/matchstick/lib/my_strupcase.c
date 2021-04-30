/*
** EPITECH PROJECT, 2019
** MY_STRUPCASE
** File description:
** strupcase
*/
#include "../inc/my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return (str);
}
