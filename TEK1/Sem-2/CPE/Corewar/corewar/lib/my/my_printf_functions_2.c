/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_functions_2.c
*/

#include <stdarg.h>
#include <errno.h>
#include "../../include/my.h"

void my_flag_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void my_flag_mod(va_list ap)
{
    my_putchar('%');
}

void my_flag_m(va_list ap)
{
    my_put_nbr(errno);
}

void my_flag_bigs(va_list ap)
{
    char *str = va_arg(ap, char *);

    for (int i = 0; str[i]; i += 1) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_put_nbr(str[i]);
        } else
            my_putchar(str[i]);
    }
}

void my_flag_u(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}