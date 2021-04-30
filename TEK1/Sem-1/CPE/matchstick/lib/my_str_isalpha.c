/*
** EPITECH PROJECT, 2019
** MY_STR_ISALPHA
** File description:
** str_isalpha
*/

#include "../inc/my.h"

int my_str_isalpha(char const *str)
{
    int i = -1;
    int is_alpha = 1;

    while (str[(i = i + 1)] != '\0')
        if (!((str[i] < 123 && str[i] > 96) || (str[i] > 64 && str[i] < 91)))
            is_alpha = 0;
    return (is_alpha);

}
