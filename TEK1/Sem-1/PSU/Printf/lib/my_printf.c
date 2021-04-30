/*
** EPITECH PROJECT, 2019
** MY_PRINTF
** File description:
** Printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../inc/my.h"

void my_printf(char *str, ...)
{
    const int j = 0;
    int i = 0;
    va_list my_tab;

    va_start(my_tab, str);
    for (int i = 0; str[i] != 0;) {
        if (str[i] == '%') {
            if (redirect_one_to_ten(str, i, &my_tab) == 1)
                ++i;
            else if (redirect_ten_to_twenty(str, i, &my_tab) == 1)
                ++i;
            else if (redirect_ten_to_thirteen(str, i, &my_tab) == 1)
                i += 2;
            else
                my_putchar('%');
        } else
            my_putchar(str[i]);
        ++i;
    }
}