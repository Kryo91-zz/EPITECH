/*
** EPITECH PROJECT, 2019
** MY_STR_ISUPPER
** File description:
** str_isupper
*/

#include "../inc/my.h"

int my_str_isupper(char const *str)
{
    int i = -1;
    int is_upper = 1;

    while (str[(i = i + 1)] != '\0')
        if (!(str[i] < 64 && str[i] > 91))
        is_upper = 0;
    return (is_upper);

}
