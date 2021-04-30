/*
** EPITECH PROJECT, 2019
** MY_PRINTF
** File description:
** Printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../inc/my.h"

void my_disp_binary(va_list *my_tab)
{
    unsigned int bin = va_arg(*my_tab, int);

    my_putnbr_base(bin, "01");
}

void my_disp_hex_maj(va_list *my_tab)
{
    unsigned int hexa = va_arg(*my_tab, int);

    my_putnbr_base(hexa, "0123456789ABCDEF");
}

void my_disp_hex_min(va_list *my_tab)
{
    unsigned int hex = va_arg(*my_tab, int);

    my_putnbr_base(hex, "0123456789abcdef");
}

void my_disp_octo(va_list *my_tab)
{
    unsigned int octo = va_arg(*my_tab, int);

    my_putnbr_base(octo, "01234567");
}

void my_disp_long_num(va_list *my_tab)
{
    long nbr = va_arg(*my_tab, int);

    my_put_nbr(nbr);
}