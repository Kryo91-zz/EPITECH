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

int redirect_one_to_ten(char *str, int i, va_list *my_tab)
{
    if (str[i+1] == 'c') {
        my_disp_char(my_tab);
        return (1);
    }
    if (str[i+1] == 's') {
        my_disp_str(my_tab);
        return (1);
    }
    if (str[i+1] == 'd') {
        my_disp_nbr(my_tab);
        return (1);
    }
    if (str[i+1] == 'i') {
        my_disp_nbr(my_tab);
        return (1);
    }
    if (redi_redi(str, i, my_tab) == 1)
        return (1);
    return (0);
}

int redirect_ten_to_twenty(char *str, int i, va_list *my_tab)
{
    if (str[i+1] == 'l') {
        my_disp_long_num(my_tab);
        return (1);
    }
    if (str[i+1] == 'u') {
        my_disp_unsi_num(my_tab);
        return (1);
    }
    return (0);
}

void my_disp_octo_plus_zero(va_list *my_tab)
{
    unsigned int octo = va_arg(*my_tab, int);

    my_putchar('0');
    my_putnbr_base(octo, "01234567");
}

void my_disp_hex_plus_zero_min(va_list *my_tab)
{
    unsigned int hex = va_arg(*my_tab, int);

    my_putstr("0x");
    my_putnbr_base(hex, "0123456789abcdef");
}

void my_disp_hex_plus_zero_max(va_list *my_tab)
{
    unsigned int hex = va_arg(*my_tab, int);

    my_putstr("0X");
    my_putnbr_base(hex, "0123456789ABCDEF");
}