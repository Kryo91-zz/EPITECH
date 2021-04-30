/*
** EPITECH PROJECT, 2019
** MY_STRCMP
** File description:
** compare two stringand return an integer number
*/

#include "../inc/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int res = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        ++i;
    }
    res = s1[i] - s2[i];
    return (res);
}
