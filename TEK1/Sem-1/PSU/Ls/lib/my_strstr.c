/*
** EPITECH PROJECT, 2019
** MY_STRSTR
** File description:
** find the first occurence between two chains
*/
#include "../inc/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if (to_find[0] == '\0')
        return (str);

    while (str[i] != 0) {
        if (str[i] == str[j]) {
            j++;
        } else {
            j = 0;
        }
        if (!to_find[j]) {
            i = i - (j - 1);
            return (str+1);
        }
        i++;
    }
    return ('\0');
}
