/*
** EPITECH PROJECT, 2019
** MY_SHOWSTR
** File description:
** print a string with no printable character
*/

#include "../inc/my.h"

void convert_hexa(char c)
{
    my_putchar((c / 16) + 48);
    if ((c % 16) < 10) {
        my_putchar((c % 16) + 48);
    }
    if ((c % 16) >= 10) {
        my_putchar(c + 87);
    }
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] < '\0'; i += 1) {
        if (str[i] < 32 || str[i] == 127) {
            convert_hexa(str[i]);
        }else{
            my_putchar(str[i]);
        }
    }
    return (0);
}