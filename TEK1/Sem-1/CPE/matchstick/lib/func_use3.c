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

void my_disp_unsi_num(va_list *my_tab)
{
    unsigned nbr = va_arg(*my_tab, int);

    my_put_unsi_num(nbr);
}

int redi_redi(char *str, int i, va_list *my_tab)
{
    if (str[i+1] == '%') {
        my_disp_perc(my_tab);
        return (1);
    }
    if (str[i+1] == 'n') {
        my_disp_len(my_tab, str);
        return (1);
    }
    if (str[i+1] == 'b') {
        my_disp_binary(my_tab);
        return (1);
    }
    if (redirec_redi(str, i, my_tab) == 1)
        return (1);
    return (0);
}

int redirec_redi(char *str, int i, va_list *my_tab)
{
    if (str[i+1] == 'X') {
        my_disp_hex_maj(my_tab);
        return (1);
    }
    if (str[i+1] == 'x') {
        my_disp_hex_min(my_tab);
        return (1);
    }
    if (str[i+1] == 'o') {
        my_disp_octo(my_tab);
        return (1);
    }
    return (0);
}

int redirect_ten_to_thirteen(char *str, int i, va_list *my_tab)
{
    if (str[i+1] == '#') {
        if (str[i+2] == 'o') {
            my_disp_octo_plus_zero(my_tab);
            return (1);
        }
        if (str[i+2] == 'x') {
            my_disp_hex_plus_zero_min(my_tab);
            return (1);
        }
        if (str[i+2] == 'X') {
            my_disp_hex_plus_zero_max(my_tab);
            return (1);
        }
    }
    return (0);
}