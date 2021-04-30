/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf_functions_1.c
*/

#include <stdarg.h>
#include "../../include/my.h"

void my_flag_p(va_list ap)
{
    my_putstr("0x");
    my_putnbr_base(va_arg(ap, long long), "0123456789abcdef");
}

void my_flag_x(va_list ap)
{
    my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

void my_flag_bigx(va_list ap)
{
    my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}

void my_flag_o(va_list ap)
{
    my_putnbr_base(va_arg(ap, unsigned int), "01234567");
}

void my_flag_b(va_list ap)
{
    my_putnbr_base(va_arg(ap, unsigned int), "01");
}