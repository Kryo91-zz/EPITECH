/*
** EPITECH PROJECT, 2019
** EvalExpr
** File description:
** Basic Function
*/

#include <stdlib.h>
#include <unistd.h>

int    eval_expr(char const *str);

void    my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_put_nbr(int nb)
{
    if (nb < 0)
    {
        my_putchar('-');
        my_put_nbr(-nb);
        return;
    }
    if (nb >= 10)
    {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
}

int    my_convert_chars_to_nb(char **c)
{
    int num = 0;

    while (**c >= '0' && **c <= '9') {
        num = num * 10 + (**c - 48);
        (*c)++;
    }
    return (num);
}

int    my_putstr(char const *str)
{
    int i;

    i = 0;

    while (str [i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (NULL);
}

int    my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}