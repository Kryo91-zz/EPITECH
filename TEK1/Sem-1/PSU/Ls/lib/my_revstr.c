/*
** EPITECH PROJECT, 2019
** MY_REVSTR
** File description:
** write function that reverse a string
*/

#include "../inc/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char str2;

    while (str[j] != '\0') {
        j++;
    }
    j = j - 1;
    while (i < j) {
        str2 = str[i];
        str[i] = str [j];
        str [j] = str2;
        i++;
        j--;
    }
    return (str);
}
