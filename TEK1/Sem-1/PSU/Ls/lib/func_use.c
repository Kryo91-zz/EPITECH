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

void my_disp_perc(va_list *my_tab)
{
    my_putchar('%');
}

void my_disp_str(va_list *my_tab)
{
    char *str = va_arg(*my_tab, char *);

    my_putstr(str);
}

void my_disp_char(va_list *my_tab)
{
    char c = va_arg(*my_tab, int);

    my_putchar(c);
}

void my_disp_nbr(va_list *my_tab)
{
    int nbr = va_arg(*my_tab, int);

    my_put_nbr(nbr);
}

void my_disp_len(va_list *my_tab, char *str)
{
    int i = my_strlen_perc(str);
    my_put_nbr(i);
}