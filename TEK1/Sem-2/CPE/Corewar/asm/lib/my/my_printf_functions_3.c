/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_functions_3.c
*/

#include <stdarg.h>
#include "../../include/my.h"

void my_flag_d_i(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void my_flag_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void my_flag_upper_b(va_list ap)
{
    if (va_arg(ap, int))
        write(1, "true", 4);
    else
        write(1, "false", 5);
}

void my_flag_a(va_list ap)
{
    char **tab = va_arg(ap, char **);
    char *sep = va_arg(ap, char *);
    int i = 0;

    for (; tab && tab[i] && tab[i + 1]; i++) {
        my_putstr(tab[i]);
        my_putstr(sep);
    }
    my_putstr(tab[i]);
}