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